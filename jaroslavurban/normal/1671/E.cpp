#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 998244353;

void ProGamerMove() {
	int k, n; cin >> k, n = (1 << k) - 1;
	string s, mys; cin >> s;
	int t = 0;
	vector<int> in(n), out(n);
	function<void(int)> dfs = [&] (int u) {
		in[u - 1] = t++;
		mys += s[u - 1];
		if (2 * u <= n) {
			dfs(2 * u);
			dfs(2 * u + 1);
			int m = (in[u - 1] + t + 1) / 2;
			int len = (t - in[u - 1]) / 2;
			auto x = mys.substr(in[u - 1] + 1, len);
			auto y = mys.substr(m, len);
			if (x > y) {
			for (int i = in[u - 1] + 1, j = 0; j < len; ++i, ++j) mys[i] = y[j], mys[m + j] = x[j];
			}
		}
		out[u - 1] = t;
	};
	function<ll(int)> dfs2 = [&] (int u) {
		ll res = 1;
		if (2 * u <= n) {
			res = dfs2(2 * u) * dfs2(2 * u + 1) % mod;
			int m = (in[u - 1] + out[u - 1] + 1) / 2;
			int len = (out[u - 1] - in[u - 1]) / 2;
			if (mys.substr(in[u - 1] + 1, len) != mys.substr(m, len)) res = 2 * res % mod;
		}
		return res;
	};
	dfs(1);
	cout << dfs2(1) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}