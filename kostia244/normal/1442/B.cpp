#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 101, mod = 998244353;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> c(n+2), p(n+1);
		c[0] = c[n+1] = 1<<30;
		for(int t, i = 1; i <= n; i++) {
			cin >> t;
			p[t] = i;
		}
		vector<int> b;
		for(int t, i = 1; i <= k; i++) {
			cin >> t;
			b.push_back(p[t]);
			c[p[t]] = i;
		}
		int ans = 1;
		for(auto i : b) {
			ans = ans * ((c[i-1]<c[i]) + (c[i+1]<c[i])) % mod;
		}
		cout << ans << '\n';
	}
}