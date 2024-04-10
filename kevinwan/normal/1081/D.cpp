#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;/*
int a[100000],c[100000],b[100000],at[100000],k[100000];
void die() { printf("Impossible"); getchar(); getchar(); exit(0); }
int main()
{
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i), a[i] = n - a[i], c[a[i]]++;
	int cnt = 1;
	for (i = 1; i <= n; i++) {
		if (c[i] % i)die();
		if(c[i])at[i] = cnt++;
	}
	for (i = 0; i < n; i++) {
		b[i] = at[a[i]];
		k[a[i]]++;
		if (k[a[i]] % a[i] == 0) {
			if(k[a[i]]!=c[a[i]])at[a[i]] = cnt++;
		}
	}
	printf("Possible\n");
	for (i = 0; i < n; i++)printf("%d ", b[i]);
	getchar(); getchar();
}
*/
struct edge { int a, b, c; };
bool comp(const edge&a, const edge&b) { return a.c < b.c; }
int p[100001];
int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
void merge(int a, int b) { p[find(a)] = find(b); }
vector<int> sp;
edge idk[100001];
bool isp[100001];
vector<pii> g[100001];
int down1[100001], down2[100001],up[100001];
void dfs(int x, int p) {
	for (auto th : g[x]) {
		int y = th.first;
		if (y == p)continue;
		int l = th.second;
		dfs(y, x);
		isp[x] |= isp[y];
		if (isp[y]) {
			int comp = max(down1[y], l);
			if (comp > down1[x])down2[x] = down1[x], down1[x] = comp;
			else if (comp > down2[x])down2[x] = comp;
		}
	}
}
void dfs2(int x, int p) {
	for (auto th : g[x]) {
		int y = th.first;
		if (y == p)continue;
		int l = th.second;
		up[y] = max(up[x], l);
		if (max(l, down1[y]) == down1[x])up[y] = max(up[y], max(l, down2[x]));
		else up[y] = max(up[y], max(l, down1[x]));
		dfs2(y, x);
	}
}
int main() {
	int n, m, k,x,i;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < k; i++)scanf("%d", &x), isp[x] = 1, sp.push_back(x);
	for (i = 0; i < m; i++)scanf("%d%d%d", &idk[i].a, &idk[i].b, &idk[i].c);
	sort(idk, idk +m,comp);
	for (i = 1; i <= n; i++)p[i] = i;
	for (i = 0; i < m; i++) {
		if (find(idk[i].a) == find(idk[i].b))continue;
		merge(idk[i].a, idk[i].b);
		g[idk[i].a].push_back({ idk[i].b,idk[i].c });
		g[idk[i].b].push_back({ idk[i].a,idk[i].c });
	}
	dfs(sp[0],0);
	dfs2(sp[0], 0);
	for (int s : sp) {
		printf("%d ", max(down1[s], up[s]));
	}
	getchar(); getchar();
}