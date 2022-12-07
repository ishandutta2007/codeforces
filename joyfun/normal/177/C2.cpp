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

const int N = 2005;
int n, k, m, fa[N], cnt[N];
int vis[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i, cnt[i] = 1;
	scanf("%d", &k);
	int u, v;
	while (k--) {
		scanf("%d%d", &u, &v);
		u = find(u); v = find(v);
		if (u != v) {
			fa[u] = v;
			cnt[v] += cnt[u];
		}
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &u, &v);
		u = find(u); v = find(v);
		if (u == v) vis[u] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (find(i) == i && vis[i] == 0) ans = max(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}