#include<iostream>
using namespace std;
int a[26];
char chr(char s){
	if(int('a')<=int(s) && (int('z')>=int(s)))
		return char(a[int(s)-97]);
	if(int('A')<=int(s) && (int('Z')>=int(s)))
		return char((a[int(s)-65])-32);
	return s;}
int main(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	for(int i=0;i<26;i++)
		a[int(s1[i])-97]=int(s2[i]);
	for(int i=0;i<s3.size();i++)
	cout<<chr(int(s3[i]));
}