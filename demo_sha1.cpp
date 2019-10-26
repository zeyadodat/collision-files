#include <stdio.h>
#include <stdlib.h>
#include "sha1.hpp"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <errno.h>
#include <iostream>
#include <ctime>
#include <ctype.h>
using std::string;
using std::cout;
using std::endl;
using namespace std;
const int N = 1500;
const int MAX = 26;
string GetBinaryStringFromHexString (string sHex)
		{
			string sReturn = "";
			for (size_t j = 0; j < sHex.length (); ++j)
			{
				switch (sHex [j])
				{
					case '0': sReturn.append ("0000"); break;
					case '1': sReturn.append ("0001"); break;
					case '2': sReturn.append ("0010"); break;
					case '3': sReturn.append ("0011"); break;
					case '4': sReturn.append ("0100"); break;
					case '5': sReturn.append ("0101"); break;
					case '6': sReturn.append ("0110"); break;
					case '7': sReturn.append ("0111"); break;
					case '8': sReturn.append ("1000"); break;
					case '9': sReturn.append ("1001"); break;
					case 'a': sReturn.append ("1010"); break;
					case 'b': sReturn.append ("1011"); break;
					case 'c': sReturn.append ("1100"); break;
					case 'd': sReturn.append ("1101"); break;
					case 'e': sReturn.append ("1110"); break;
					case 'f': sReturn.append ("1111"); break;
				}
			}
			//cout<<"\nBinary value: "<<sReturn<<endl;
			return sReturn;
		}

string printRandomString(int n) 
{ 
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 
string * compute_hash(string array[]){
	int i;
	string* out = new string[N]; 
	for (i=0; i<N ; i++){
    SHA1 checksum;
    if(i==6){
    	continue;
    	cout << "Test:     16,777,216 repititions of abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno" << endl;
    	for (int j = 0; j < 16777216; ++j)
    	{
        checksum.update(array[6]);
 		}
 		const string hash = checksum.final();
    	out[i] = hash;
    	cout << "The SHA-1 of \"" << array[i] << "\" is: " << hash << endl;
 		continue;
 		}
    checksum.update(array[i]);
    const string hash = checksum.final();
    out[i] = hash;
    cout << "The SHA-1 of \"" << array[i] << "\" is: " << hash << endl;
}
return out;
}
float * hamm_distance(string array1[], string array2[],fstream& data){
 	int count = 0;
 	string s1,s2,s3,s4;
	size_t k,p;
	float * percentage = new float[N];
	cout<<"\nThe hamming distance results stroed in hamm.txt file.n"<<endl;
	for(p=0;p<N;p++){
	s1 = array1[p];
	s2 = array2[p];
	s3 = GetBinaryStringFromHexString(s1);
	s4 = GetBinaryStringFromHexString(s2);
    
    	for (k=0; k<s3.length(); k++)
        	{
            	if (s3[k] != s4[k])
            	{
                	count += 1;
            	}
        	}
        percentage[k] = 100*(float)count/160;
        if(percentage[k]>43){
        data<<p<<" "<<count<<" "<<percentage[k]<<" %"<<endl;}
        count = 0; 
    }
    return percentage;
 }
 int * hitrate(string value1[], string value2[], fstream& hit){
 	int hit_count = 0;
 	int flag=0;
 	string h1,h2;
 	size_t l,m;
 	int * hitt = new int[N];
 	cout<<"\nHit charecters stored in the hit_charecters.txt.."<<endl;
 	hit<<"M"<<" "<<"count"<<" "<<"position"<<endl;
 	for(l = 0; l<N ; l++){
 		h1 = value1[l];
 		h2 = value2[l];
 		for(m = 0; m<h1.length(); m++){
 			if(h1[m] == h2[m]){
 				hit_count +=1;
 				flag = m;
 			}
 		}
 		hitt[m] = hit_count;
 		if(hitt[m]<=2){
 		hit<<l<<" "<<hit_count<<" "<<flag<<endl;}
 		hit_count = 0;
 		flag = 0;
 	}
 	return hitt;
 }
int main(int argc , const char** argv)
{
	fstream data,hit;
	data.open("test_data.txt",fstream::out); //add ,fstream::app to append values.
	hit.open("hit_characters_test_data.txt",fstream::out);
	string test1[N];
	string test2[N];
	string temp;
	srand(time(NULL)); 
    int n,g1,g2,g3,g4,g5,g6,g7,g8,g9,g10;
    for(int b =0; b<N;b++){
    	n =(rand()%100)+1; 
    	g1 = rand()%n;
    	//g2 = rand()%n;
    	//g3 = rand()%n;
    	//g4 = rand()%n;
    	//g5 = rand()%n;
    	//g6 = rand()%n;
    	//g7 = rand()%n;
    	//g8 = rand()%n;
    	//g9 = rand()%n;
    	//g10 = rand()%n;
    	test1[b] = printRandomString(n);
    	temp = test1[b];
    	temp[g1] = toupper(temp[g1]);
    	//temp[g2] = toupper(temp[g2]);
    	//temp[g3] = toupper(temp[g3]);
    	//temp[g4] = toupper(temp[g4]);
    	//temp[g5] = toupper(temp[g5]);
    	//temp[g6] = toupper(temp[g6]);
    	//temp[g7] = toupper(temp[g7]);
    	//temp[g8] = toupper(temp[g8]);
    	//temp[g9] = toupper(temp[g9]);
    	//temp[g10] = toupper(temp[g10]);
    	test2[b] = temp;
    	cout<<test1[b]<<endl;
    	cout<<test2[b]<<endl;
    }
    
     string input1[37] = {
     "abc123_owlstead_1255",
     "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
     "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
     "A million repetitions of 'a'",
     "The quick brown fox jumps over the lazy dog",
     "The quick brown fox jumps over the lazy cog",
     "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno",
     "b b b",
     "abcde",
     "a \x00 b \x7f c \x80 d \xff e \xc3\xf0 f",
     "abc",
     "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
     string input2[37] = {
     "abc123_owlstead_59131",
     "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq~",
     "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu~",
     "A million repetitions of 'a~'",
     "The quick brown fox jumps over the lazy mog",
     "The quick brown fox jumps over the lazy dog",
     "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno~",
     "b b",
     "abcde~",
     "a \x00 b \x7f c \x80 d \xff e \xc3\xf0 f",
     "abc~",
     "b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","a"};
	string value;
	string* hash1;
	string* hash2;
	float* hamm_dist;
	int* char_hit;
	clock_t c_start = std::clock();

if(argc < 2)
{
	
hash1=compute_hash(input1);
hash2=compute_hash(input2);
hamm_dist = hamm_distance(hash1,hash2,data);
char_hit = hitrate(hash1,hash2,hit);
cout<<"\nTEST>>>>>>>>>>>>>>"<<hamm_dist[0]<<endl;
        //return 1;
 }
 else {
     string filename;
     filename = argv[1];
     std::ifstream stream(filename.c_str(), std::ios::binary);
       SHA1 checksum;
	checksum.update(stream);
	value = checksum.final();
	cout<<"\nThe output hash of file: "<<argv[1]<<": "<<value<<endl;
}
  
clock_t c_end = std::clock();
long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
cout << "CPU time used: " << time_elapsed_ms / 1000.0 << " s\n";
data.close();
hit.close();
    return 0;
}
