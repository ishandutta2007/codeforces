#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

#define lowbit(x) (x&(-x))
const int N = 200005;

int n, m, p[N], pr[N];
ll ans[N];
vi fac[N];
vector<pii> q[N];

ll bit[N];

void add(int x, int w) {
	while (x < N) {
		bit[x] += w;
		x += lowbit(x);
	}
}

void add(int l, int r, int w) {
	add(l, 1); add(r + 1, -1);
}

ll get(int x) {
	ll ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i) fac[j].pb(i);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		q[r].pb(mp(l, i));
	}
	for (int i = 1; i <= n; i++) {
		pr[p[i]] = i;
		for (int j = 0; j < sz(fac[p[i]]); j++) {
			int x = fac[p[i]][j];
			if (pr[x]) add(1, pr[x], 1);
		}
		for (int j = p[i] + p[i]; j <= n; j += p[i])
			if (pr[j]) add(1, pr[j], 1);
		for (int j = 0; j < sz(q[i]); j++)
			ans[q[i][j].se] = get(q[i][j].fi);
	}
	for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
	return 0;
}