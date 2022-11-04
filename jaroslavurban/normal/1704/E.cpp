#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod = 998244353;
using T = __int128;
const T MX = __uint128_t(__int128_t(-1L)) >> 1;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<T> a(n);
	for (auto& v : a){
		int x; cin >> x;
		v = x;
	}
	vector<vector<int>> g(n);
	for (int u, v, i = 0; i < m; ++i) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
	}
	int res = 0;
	auto simul = [&] () {
		++res;
		vector<bool> gives(n);
		for (int i = 0; i < n; ++i) if (a[i] > 0) gives[i] = true;
		for (int u = 0; u < n; ++u) if (gives[u]) {
			--a[u];
			for (int v : g[u]) ++a[v];
		}
	};
	for (int i = 0; i <= n && count(a.begin(), a.end(), 0) != n; ++i) simul();
	auto simul2 = [&] () {
		vector<int> has(n);
		for (int u = 0; u < n; ++u) if (a[u])
			for (int v : g[u]) ++has[v];
		T mn = MX;
		for (int u = 0; u < n; ++u) if (!has[u] && a[u]) mn = min(mn, a[u]);
		assert(mn != MX);
		for (int u = 0; u < n; ++u) if (a[u]) a[u] += mn * (has[u] - 1);
		res = (res + (mn % mod)) % mod;
		for (int i = 0; i < n; ++i) assert(a[i] >= 0);
	};
	while (count(a.begin(), a.end(), 0) != n) simul2();
	cout << res << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}