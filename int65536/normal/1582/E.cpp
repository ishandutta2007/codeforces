#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<ll> s0(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s0[i + 1] = s0[i] + a[i];
		}
		auto s = [&](int i, int j) {
			return s0[j + 1] - s0[i];
		};
		int m = 0;
		while (m * (m + 1) / 2 <= n) {
			++m;
		}
		m += 2;
		const ll INF = (1LL << 62);
		vector<vector<ll>> f(m + 1, vector<ll>(m));
		vector<vector<ll>*> g(n + 1);
		for (int i = 0; i < g.size(); ++i) {
			g[i] = &f[i % (m + 1)];
		}
		(*g[n])[0] = INF;
		for (int i = n - 1; i >= 0; --i) {
			auto& cur = (*g[i]);
			cur[0] = INF;
			auto& prev = (*g[i + 1]);;
			for (int k = 1; k < m; ++k) {
				cur[k] = prev[k];
				if (i + k - 1 < n) {
					ll s2 = s(i, i + k - 1);
					if (s2 < (*g[i + k])[k - 1]) {
						cur[k] = max(cur[k], s2);
					}
				}
			}
		}
		int ret = 1;
		for (int k = 1; k < m; ++k) {
			if (f[0][k] > 0) {
				ret = k;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}