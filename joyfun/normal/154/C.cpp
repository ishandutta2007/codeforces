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

typedef unsigned long long ull;
const int N = 1000005;
ull sd = 123123123ULL;
int n, m, u[N], v[N];
vi g[N];
ull h[N];

ll get(int tp) {
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 0; i < m; i++) g[u[i]].pb(v[i]), g[v[i]].pb(u[i]);
	for (int i = 1; i <= n; i++) {
		if (tp) g[i].pb(i);
		sort(g[i].begin(), g[i].end());
		h[i] = 0;
		for (int j = 0; j < sz(g[i]); j++)
			h[i] = h[i] * sd + g[i][j];
	}
	ll ans = 0;
	sort(h + 1, h + 1 + n);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n && h[i] == h[j]) j++;
		int len = j - i;
		ans += 1ll * len * (len - 1) / 2;
		i = j - 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);
		g[u[i]].pb(v[i]); g[v[i]].pb(u[i]);
	}

	ll ans = 0;
	ans += get(0) + get(1);
	printf("%lld\n", ans);
	return 0;
}