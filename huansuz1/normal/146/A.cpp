#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,x,y;
string s,t;

int main(){
	cin>>n>>s;
	for (int i=0; i<n/2; i++){
		x+=s[i]-'0';
	if (s[i]=='4' || s[i]=='7') m++;
	}
	for (int i=n/2; i<n; i++) {
		y+=s[i]-'0';
		if (s[i]=='4' || s[i]=='7') m++;
	}
	if (m==n && x==y) cout << "YES" ; else cout << "NO";

	
	return 0;
}