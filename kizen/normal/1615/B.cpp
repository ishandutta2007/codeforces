#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int l, r; cin >> l >> r;
		int ans = r - l;
		--l;
		for(int i = 1; i <= (1 << 20); i <<= 1){
			int cnt = 0;
			cnt += r / (i * 2) * i + max(0ll, r % (i * 2) - i + 1);
			cnt -= l / (i * 2) * i + max(0ll, l % (i * 2) - i + 1);
			ans = min(ans, r - l - cnt);
		}
		cout << ans << '\n';
	}
	return 0;
}