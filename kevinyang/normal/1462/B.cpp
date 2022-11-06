#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool f = false;
		if(s.substr(0,4)=="2020")f = true;
		if(s.substr(0,3)=="202"&&s[n-1]=='0')f = true;
		if(s.substr(0,2)=="20"&&s.substr(n-2,2)=="20")f = true;
		if(s[0]=='2'&&s.substr(n-3,3)=="020")f = true;
		if(s.substr(n-4,4)=="2020")f = true;
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}