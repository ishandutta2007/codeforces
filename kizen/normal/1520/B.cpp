#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = 0;
		for(int i = 1; i <= 9; ++i){
			int val = i;
			while(val <= n){
				++ans;
				val = val * 10 + i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}