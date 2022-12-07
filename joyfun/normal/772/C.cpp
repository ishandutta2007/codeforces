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

const int N = 200005;
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {x = 1; y = 0; return a;}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int n, m, vis[N], dp[N], p[N];
vi g[N];
int ans = 0, u, last = 1;

void go(int u) {
	if (u == 0) return;
	go(p[u]);
	int x = 0, y = 0;
	for (int i = 0; i < sz(g[u]); i++) {
		int d = exgcd(last, m, x, y);
		if (d < 0) d = -d;
		x = (x % m + m) % m;
		printf("%d ", (int)(1ll * x * g[u][i] / d % m));
		last = g[u][i];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		vis[x] = 1;
	}
	for (int i = 1; i < m; i++) if (!vis[i]) g[__gcd(i, m)].pb(i);
	dp[1] = sz(g[1]); p[1] = 0;
	for (int i = 1; i < m; i++) {
		if (dp[i] > ans) ans = dp[i], u = i;
		for (int j = i * 2; j < m; j += i) {
			if (dp[i] + sz(g[j]) > dp[j]) dp[j] = dp[i] + sz(g[j]), p[j] = i;
		}
	}
	printf("%d\n", ans + !vis[0]);
	go(u);
	if (!vis[0]) printf("0");
	return 0;
}