#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
   
int main(){
	int n,x=0,z=0;
	string s;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>s;
		z=0;
		if (s[0]=='+') z++;
		if (s[1]=='+') z++;
		if (s[2]=='+') z++;
		if (z==2) x++; else x--;
	}	
	cout<<x;	
	
	return 0;          
}