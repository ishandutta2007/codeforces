#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		while(q--){
			int a,b;
			cin >> a >> b;
			bool f1 = false;
			a--; b--;
			for(int i = 0; i<a; i++){
				if(s[i]==s[a])f1 = true;
			}
			for(int i = b+1; i<n; i++){
				if(s[i]==s[b])f1 = true;
			}
			if(f1){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}