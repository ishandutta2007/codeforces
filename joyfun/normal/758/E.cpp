#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 200005;
const ll inf = (1ll<<60);

int n, x[N], y[N], w[N], p[N], d[N];
ll s[N];

vi g[N];

bool dfs(int u) {
	s[u] = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int id = g[u][i];
		int v = y[id];
		if (!dfs(v)) return false;
		if (p[id] < s[v]) return false;
		d[id] = min(1ll * w[id] - 1, p[id] - s[v]);
		p[id] -= d[id]; w[id] -= d[id];
		s[u] += s[v] + w[id];
	}
	return true;
}

ll s2[N];

void go(int u, ll yu) {
	s2[u] = 0;
	ll sb = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int id = g[u][i];
		int v = y[id];
		sb += s[v] + w[id];
	}

	for (int i = 0; i < g[u].size(); i++) {
		int id = g[u][i];
		int v = y[id];
		int tmp = min(yu - sb, 1ll * d[id]);
		sb -= s[v] + w[id];
		p[id] += tmp; w[id] += tmp;
		go(v, min(yu - sb - w[id], 1ll * p[id]));
		s2[u] += s2[v] + w[id];
		yu -= s2[v] + w[id];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d%d", &x[i], &y[i], &w[i], &p[i]);
		g[x[i]].push_back(i);
	}
	if (!dfs(1)) printf("-1\n");
	else {
		printf("%d\n", n);
		go(1, inf);
		for (int i = 1; i < n; i++) printf("%d %d %d %d\n", x[i], y[i], w[i], p[i]);
	}
	return 0;
}