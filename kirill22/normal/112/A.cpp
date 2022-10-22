#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,h,ans=0;
	string s,s1;
	cin >>s>> s1;
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
		s1[i]=tolower(s1[i]);
	}
	if (s>s1) cout << 1;
	else if (s<s1) cout << -1;
	else cout << 0;
	return 0;
}