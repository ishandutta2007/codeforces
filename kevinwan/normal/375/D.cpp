#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
#define siz 300
struct query { int l, r, num, ind; };
bool comp(const query&a, const query&b) { if (a.l / siz < b.l / siz)return 1; if (a.l / siz == b.l / siz && a.r < b.r)return 1; return 0; }
int id[maxn], c[maxn],col[maxn],s[maxn],ans[maxn],nu[maxn],k[maxn];
query q[maxn];
vector<int> g[maxn];
int n, m,cnt=1;
void dfs(int x, int p) {
	id[x] = cnt++,s[x]=1;
	for (int y : g[x]) {
		if (y == p)continue;
		dfs(y, x);
		s[x] += s[y];
	}
}
int main() {
	scanf("%d%d", &n,&m);
	int i,j, a, b;
	for (i = 1; i <= n; i++)scanf("%d", col + i);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	dfs(1, 0);
	for (i = 1; i <= n; i++)c[id[i]] = col[i];
	for (i = 0; i < m; i++)scanf("%d%d", &a, &b), q[i].l = id[a], q[i].r = id[a] + s[a] - 1, q[i].num = b, q[i].ind = i;
	sort(q, q + m, comp);
	int lp=1, rp=0;
	for (i = 0; i < m; i++) {
		while (lp > q[i].l)lp--,nu[c[lp]]++,k[nu[c[lp]]]++;
		while (rp < q[i].r)rp++, nu[c[rp]]++, k[nu[c[rp]]]++;
		while (lp < q[i].l)k[nu[c[lp]]]--, nu[c[lp]]--, lp++;
		while (rp > q[i].r)k[nu[c[rp]]]--, nu[c[rp]]--, rp--;
		ans[q[i].ind] = k[q[i].num];
	}
	for (i = 0; i < m; i++)printf("%d\n", ans[i]);
	getchar(); getchar();
}