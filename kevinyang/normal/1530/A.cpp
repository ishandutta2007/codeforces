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
		int mn = 0;
		for(int i = 0; i<s.length(); i++){
			mn = max(mn,(int)s[i]);
		}
		cout << mn-'0' << "\n";
	}
	return 0;
}