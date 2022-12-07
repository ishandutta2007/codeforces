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

const int N = 100005;
int n, m, a[N], d[N];
vi g[N];
queue<int> Q;
vi ans;

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		if (!a[i]) Q.push(i);
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		ans.pb(u);
		d[u]++;
		for (int i = 0; i < sz(g[u]); i++) {
			int v = g[u][i];
			d[v]++;
			if (d[v] == a[v])
				Q.push(v);
		}
	}
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d ", ans[i]); printf("\n");
	return 0;
}