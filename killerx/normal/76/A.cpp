#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
// 	freopen("c.in", "r", stdin);
// 	freopen("c.out", "w", stdout);
	int n, m, G, S;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &G, &S);
	struct Edge { int u, v, g, s; };
	auto compg = [&](const Edge &a, const Edge &b) { return a.g < b.g; };
	auto comps = [&](const Edge &a, const Edge &b) { return a.s < b.s; };
	vector<Edge> e, te;
	rep(i, m) {
		int u, v, g, s;
		scanf("%d %d %d %d", &u, &v, &g, &s);
		--u, --v;
		e.pb({u, v, g, s});
	}
	sort(e.begin(), e.end(), compg);
	struct UF {
		vector<int> fa, sz;
		UF(int n) {
			fa.resize(n);
			sz.resize(n);
			rep(i, n) fa[i] = i, sz[i] = 1;
		}
		int find(int x) {
			return x == fa[x] ? x : fa[x] = find(fa[x]);
		}
		bool merge(int x, int y) {
			x = find(x), y = find(y);
			if (x == y) return false;
			if (sz[x] > sz[y]) fa[y] = x, sz[x] += sz[y];
			else fa[x] = y, sz[y] += sz[x];
			return true;
		}
	};
	auto rebuild = [&]() {
		int ans = 0;
		UF uf(n);
		vector<Edge> nte;
		rep(i, te.size()) {
			if (uf.merge(te[i].u, te[i].v)) {
				ans = te[i].s;
				nte.pb(te[i]);
			}
		}
		te.swap(nte);
		return uf.sz[uf.find(0)] == n ? ans : 0x3f3f3f3f;
	};
	ll ans = 4e18;
	rep(i, m) {
		te.insert(lower_bound(te.begin(), te.end(), e[i], comps), e[i]);
		int cg = e[i].g, cs = rebuild();
		if (cs < 0x3f3f3f3f) ans = min(ans, 1LL * S * cs + 1LL * G * cg);
	}
	printf("%lld\n", ans >= 4e18 ? -1 : ans);
	return 0;
}