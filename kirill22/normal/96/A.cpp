#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,h,ans=0;
	string s;
	cin >>s;
	if (s.find("1111111")!=string::npos || s.find("0000000")!=string::npos ){
		yes;
	}
	else no;
	return 0;
}