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
		string t;
		cin >> t;
		bool f = false;
		for(int i = 1; i<=n; i++){
			if(s[i]=='1'&&t[i]=='1')f = true;
		}
		if(f)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}