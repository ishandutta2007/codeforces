#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int ans = 0;
		++m;
		for(int i = 34; i >= 0; --i){
			int ni = (n & (1ll << i)), mi = (m & (1ll << i));
			if(ni == mi) continue;
			if(ni && !mi) break;
			ans += (1ll << i);
		}
		cout << ans << '\n';
	}
	return 0;
}