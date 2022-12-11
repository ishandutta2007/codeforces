// luogu-judger-enable-o2
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int N = 4e5 + 10;

struct node {
	int fir, l, r, id, k;
	bool operator < (const node &b) const {
		return fir < b.fir || (fir == b.fir && r < b.r);
	}
} a[N];
int n, m, q, c[N], dl[N], dr[N], idx, ans[N], col[N], cnt[N], cc[N];
vector<int> G[N];

void dfs(int u, int fa = 0) {
	dl[u] = ++ idx; col[idx] = c[u];
	for(int &v : G[u]) if(v != fa) dfs(v, u);
	dr[u] = idx;
}
void upd(int u, int d) {
	u = col[u];
	if(d == 1) {
		cnt[u] ++;
		cc[cnt[u]] ++;
	} else {
		cc[cnt[u]] --;
		cnt[u] --;
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i ++) scanf("%d", c + i);
	int u, v;
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1); m = ceil(n / sqrt(q));
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d", &u, &v);
		a[i] = {dl[u] / m, dl[u], dr[u], i, v};
	}
	sort(a + 1, a + q + 1);
	int l = a[1].l, r = a[1].l - 1;
	for(int i = 1; i <= q; i ++) {
		while(l > a[i].l) upd(-- l, 1);
		while(r < a[i].r) upd(++ r, 1);
		while(l < a[i].l) upd(l ++, -1);
		while(r > a[i].r) upd(r --, -1);
		ans[a[i].id] = cc[a[i].k];
	}
	for(int i = 1; i <= q; i ++)
		printf("%d\n", ans[i]);
	return 0;
}