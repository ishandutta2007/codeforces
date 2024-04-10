#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,a[1234]; 
string s;
int main(){
	cin>>s;
	for (int i=0; i<s.length(); i++)
		if (s[i]!='+') a[n++]=s[i]-48;	
	sort(a,a+n);
	cout<<a[0];
	for (int i=1; i<n; i++)
	cout<<"+"<<a[i];
}