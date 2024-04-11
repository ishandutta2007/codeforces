#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<11, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll sum = 0, n, w;
		cin >> n >> w;
		vector<array<ll, 2>> a;
		ll pos = 1;
		for(ll t, i = 1; i <= n; i++) {
			cin >> t;
			if(t <= w) a.push_back({t, i}), sum += t;
		}
		ll need = (w+1)/2;
		if(sum < need) {cout << "-1\n"; continue;}
		ll cur = 0;
		vector<ll> sol;
		sort(all(a));
		for(auto &[i, idx] : a) {
			if(i >= need && i <= w) {
				sol = {idx};
				break;
			}
			cur += i;
			sol.push_back(idx);
			if(cur >= need) break;
		} 
		cout << sol.size() << '\n';
		for(auto i : sol) cout << i << " ";cout << '\n';
	}
}