#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(string s, int d){
	for(int i = 0; i<s.length(); i++){
		if(s[i]=='0'+d)return true;
	}
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int q,d;
		cin >> q >> d;
		while(q--){
			int n;
			cin >> n;
			while(n>=d){
				if(f(to_string(n),d))break;
				n-=d;
			}
			if(f(to_string(n),d))cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}