#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t, n;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> a >> b >> n;
		vector<vector<int>> X(a+1), Y(b+1);
		vector<int> f(n), g(n);
		for(auto &i : f) cin >> i;
		for(auto &i : g) cin >> i;
		for(int i = 0; i < n; i++) {
			X[f[i]].push_back(g[i]);
			Y[g[i]].push_back(f[i]);
		}
		ll ans = n*1ll*(n-1)/2;
		for(auto &i : X) ans -= i.size()*1ll*((int)i.size()-1)/2;
		for(auto &i : Y) ans -= i.size()*1ll*((int)i.size()-1)/2;
		cout << ans << '\n';
	}
}