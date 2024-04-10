#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string s;

int main(){
	cin >> s;
	
	if (s.length() >=3) {
	for (int i = 0; i < s.length()-2; i++) {
		string l = "";
		for (int j = i; j <=i+2; j++)
			l += s[j]; 
		if (l == "144") {s[i]='-'; s[i+1]='-';s[i+2]='-'; i+=2;}
	}}
	if (s.length()>=2){
	
		for (int i = 0; i < s.length()-1; i++) {
		string l = "";
		for (int j = i; j <i+2; j++)
			l += s[j]; 
		if (l == "14") {s[i]='-'; s[i+1]='-';i+=1;}
		}} 
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') s[i]='-';
	}
	for (int i=0; i<s.length(); i++)
		if (s[i] != '-') {cout<<"NO"; exit(0);}
	cout<<"YES"; 
	
	
	return 0;
}