#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		if(l*2<=r){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}