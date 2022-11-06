#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s[0]+s[1]+s[2]==s[3]+s[4]+s[5]){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}