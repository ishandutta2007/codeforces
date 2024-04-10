#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n=0,a[1234]; 
string s;
int main(){
	cin>>s;
	for (int i=0; i<s.length(); i++)
		if (s[i]=='4' || s[i]=='7') n++;
	if (n==4 || n==7) cout<<"YES"; else cout<<"NO";
}