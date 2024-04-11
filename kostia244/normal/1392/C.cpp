#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
		vector<array<int, 2>> f;
		int n; cin >> n;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			if(f.size() && f.back()[1] <= t) f.back()[1] = t;
			else f.push_back({t, t});
		}
		ll ans = 0;
		while(f.size() > 1) {
			n = f.size();
			int d = max(0, f[n-2][1]-f[n-1][0]);
			ans += d;
			f[n-1][1] = f[n-1][1] + d;
			f.pop_back();
		}
		cout << ans << '\n';
	}
}