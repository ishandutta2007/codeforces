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
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ans = (int)1e18;
		int sum = 0;
		for(int i = 0; i < n; ++i){
			int val = (k - sum) / (n - i);
			if(k < sum){
				val -= !!((sum - k) % (n - i));
			}
			mi(ans, max(0ll, a[0] - val) + n - i - 1);
			if(i < n - 1) sum += a[i + 1];
		}
		cout << ans << '\n';
	}
	return 0;
}