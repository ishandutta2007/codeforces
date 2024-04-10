#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, m;
int a[mxn], b[mxn];
vector <pair <int, pair <int, int> > > e;

int fa[mxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

int main() {
	scanf("%d %d", &m, &n);
	rep(i, m) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	rep(i, m + n) fa[i] = i;
	ll ans = 0;
	rep(i, m) {
		int sz; scanf("%d", &sz);
		rep(j, sz) {
			int x; scanf("%d", &x); -- x;
			e.pb(mp(a[i] + b[x], mp(i, x + m)));
			ans += a[i] + b[x];
		}
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	rep(i, e.size()) {
		int u = e[i].second.first, v = e[i].second.second, w = e[i].first;
		if (find(u) != find(v)) merge(u, v), ans -= w;
	}
	printf("%lld\n", ans);
	return 0;
}