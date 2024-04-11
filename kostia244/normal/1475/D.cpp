#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		vector<int> f(n), g(n);
		for(auto &i : f) cin >> i;
		for(auto &i : g) cin >> i;
		vector<int> F[2];
		for(int i = 0; i < n; i++) {
			F[g[i]-1].push_back(f[i]);
		}
		sort(all(F[0]), greater<>());
		sort(all(F[1]), greater<>());
		int ans = 1<<30;
		int j = 0;
		ll sum = 0;
		while(j < F[0].size() && sum < m) {
			sum += F[0][j];
			j++;
		}
		for(int i = 0; i <= F[1].size(); i++) {
			if(sum >= m) ans = min(ans, 2*i + j);
			if(i < F[1].size()) {
				sum += F[1][i];
				while(j && sum-F[0][j-1] >= m) {
					sum -= F[0][--j];
				}
			}
		}
		if(ans == 1<<30) ans = -1;
		cout << ans << '\n';
	}
}