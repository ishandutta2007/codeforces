#pragma GCC optimize("Ofast")
#pragma GCC target("avx2", "sse4")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
	const ll inf = 1LL << 60;
	const vector<int> p10 = {1, 10, 100, 1000, 10000, 100000, 1000000};
	auto upd = [&](ll &x, ll y) -> void {
		if (y > x) x = y;
	};
	auto solve = [&](int k, const vector<int> &cost) -> vector<ll> {
		vector<ll> f(1e6, -inf);
		f[0] = 0;
		rep(i, cost.size()) {
			vector<array<ll, 2> > nw(1e6, {-inf, -inf}), cur(1e6, {-inf, -inf});
			rep(j, 1e6) nw[j][0] = f[j];
			unsigned lg = 0;
			while ((1 << lg) <= k) ++lg;
			while (lg--) {
				rep(j, 1e6) rep(flag, 2) cur[j][flag] = -inf;
				rep(j, 1e6) rep(flag, 2) if (nw[j][flag] >= 0) {
					int kc = k >> lg & 1;
					rep(c, 2) {
						if (!flag && c > kc) continue;
						if (j + 1LL * (c << lg) * p10[i] < int(1e6)) {
							upd(cur[j + 1LL * (c << lg) * p10[i]][flag || c < kc],
								nw[j][flag] + 1LL * (c << lg) * cost[i]);
						}
					}
				}
				nw.swap(cur);
			}
			rep(j, 1e6) {
				f[j] = max(nw[j][0], nw[j][1]);
			}
		}
		return f;
	};
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	cin >> k;
//	k = 1e6 - 1;
	vector<int> cost(6);
	rep(i, 6) cin >> cost[i];
//	cost = {1, 2, 3, 4, 5, 6};
	vector<ll> f(solve(3 * (k - 1), cost));
	vector<ll> ans(1e6, -inf);
	rep(i, 1e6 / 3) ans[i * 3] = f[i];
	rep(i, cost.size()) {
		vector<ll> nw(1e6, -inf);
		rep(j, 1e6) {
			rep(c, 10) {
				ll w = c % 3 == 0 ? 1LL * (c / 3) * cost[i] : 0;
				if (j + c * p10[i] < 1e6) {
					upd(nw[j + c * p10[i]], ans[j] + w);
				}
			}
		}
		ans.swap(nw);
	}
	int q;
	cin >> q;
//	q = 0;
	while (q--) {
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}
	return 0;
}