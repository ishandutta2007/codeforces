#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		map<char, int> mp;
		mp[s[0]] = 1;
		int f = 1;
		for(int i = 1; i < n; ++i){
			if(s[i] != s[i - 1]){
				if(mp[s[i]]){
					f = 0;
					break;
				}
				mp[s[i]] = 1;
			}
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}