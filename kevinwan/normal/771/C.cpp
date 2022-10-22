#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
struct nd { ll c[5]; ll x; };
nd z;
nd f(nd a) {
	nd b=z;
	b.c[0] = a.c[k - 1];
	for (int i = k - 1; i; i--)b.c[i] = a.c[i - 1];
	b.x = a.x + b.c[0];
	return b;
}
nd m(nd a, nd b,int sc=1) {
	nd r=z;
	r.x = a.x + b.x*sc;
	for (int i = 0; i < k; i++)r.c[i] = a.c[i] + b.c[i] * sc;
	return r;
}
nd v[200001];
vector<int> g[200001];
void dfs(int x, int p) {
	for (int y : g[x]) {
		if (y == p)continue;
		dfs(y,x);
		v[x] = m(v[x], f(v[y]));
	}
}
void dfs1(int x, int p) {
	for (int y : g[x]) {
		if (y == p)continue;
		v[y] = m(v[y],f(m(v[x], f(v[y]), -1)));
		dfs1(y, x);
	}
	for (int y : g[x]) {
		if (y == p)continue;
		v[x] = m(v[x],v[y]);
	}
}
int main() {
	int i,a,b;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	for (i = 1; i <= n; i++)v[i].c[0] = 1;
	dfs(1, 0);
	dfs1(1, 0);
	ll ans = v[1].x;
	for (i = 1; i < k; i++)ans += v[1].c[i];
	printf("%lld", ans / 2);
	getchar(); getchar();
}