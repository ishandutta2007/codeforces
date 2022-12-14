#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int, int> cnt;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			ans += cnt[x - i];
			++cnt[x - i];
		}
		cout << ans << '\n';
	}
	return 0;
}