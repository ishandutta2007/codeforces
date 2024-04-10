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

const int N = 1000005;
int n, m;
vi p[N];
int tmp[N], ans[N];
vector<pii> q[N];

#define lowbit(x) (x&(-x))
int bit[N];

void add(int x, int w) {
	while (x < N) {
		bit[x] += w;
		x += lowbit(x);
	}
}

void add(int l, int r, int w) {
	add(l, w); add(r + 1, -w);
}

int get(int x) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l, r; scanf("%d%d", &l, &r);
		p[r].pb(l);
	}
	for (int i = 1; i <= m; i++) {
		ans[i] = n;
		int k; scanf("%d", &k);
		for (int j = 1; j <= k; j++) scanf("%d", &tmp[j]);
		tmp[0] = 0; tmp[k + 1] = 1000001;
		for (int j = 1; j <= k + 1; j++) {
			int l = tmp[j - 1] + 1;
			int r = tmp[j] - 1;
			if (l <= r) q[r].pb(mp(l, i));
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 0; j < sz(p[i]); j++)
			add(1, p[i][j], 1);
		for (int j = 0; j < sz(q[i]); j++)
			ans[q[i][j].se] -= get(q[i][j].fi);
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}