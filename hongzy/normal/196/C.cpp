#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 1510;
struct Node {
	int x, y, id;
	Node operator - (const Node &b) const {
		return (Node) {x - b.x, y - b.y, 0};
	}
	bool operator < (const Node &b) const {
		return x < b.x || (x == b.x && y < b.y);
	}
} a[N], cur;
ll cross(const Node &a, const Node &b) {
	return (ll) a.x * b.y - (ll) a.y * b.x;
}
bool cmp(const Node &a, const Node &b) {
	return cross(a - cur, b - cur) < 0;
}
int n, sz[N], ans[N];
vector<int> G[N];
void dfs0(int u, int fa = 0) {
	sz[u] = 1;
	for(int v : G[u]) if(v != fa) {
		dfs0(v, u); sz[u] += sz[v];
	}
}
void dfs(int u, int l, int r, int fa = 0) {
	int p = l + 1, nw = l;
	for(int i = l + 1; i <= r; i ++)
		if(a[nw] < a[i]) nw = i;
	if(nw != l) swap(a[nw], a[l]);
	ans[a[l].id] = u; cur = a[l];
	sort(a + l + 1, a + r + 1, cmp);
	for(int v : G[u]) if(v != fa) {
		dfs(v, p, p + sz[v] - 1, u);
		p += sz[v];
	}
}
int main() {
	scanf("%d", &n);
	for(int u, v, i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].pb(v); G[v].pb(u);
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	dfs0(1); dfs(1, 1, n);
	for(int i = 1; i <= n; i ++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}