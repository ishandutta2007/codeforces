#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		string t;
		cin >> t;
		bool f = false;
		for(int i = 0; i<s.length(); i++){
			for(int j = i; j<s.length(); j++){
				string v = s.substr(i,j-i+1);
				if(v==t)f = true;
				for(int k = j-1; k>=0; k--){
					v+=s[k];
					if(v==t)f = true;
				}
			}
		}
		if(f)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}