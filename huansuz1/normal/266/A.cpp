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
	cin>>s;
	for (int i=0; i<s.length()-1; i++)
		if (s[i]==s[i+1]) z++;
	cout<<z;
	return 0;          
}