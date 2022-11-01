#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

int n, m, q;
tuple<int, int, int> e[maxn];
int fa[maxn];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int val[maxn];
vector<int> v[maxn];
int f[maxn][25], lg[maxn], dep[maxn], dfn[maxn], rnk[maxn], cnt;

void dfs(int i){
	dep[i] = dep[f[i][0]] + 1, rnk[dfn[i] = ++cnt] = i;
	for(int j = 1;j <= 20;j++) f[i][j] = f[f[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		f[to][0] = i, dfs(to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = f[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

struct Node{
	int mn, mx, l, r, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].mn = min(t[ls(x)].mn, t[rs(x)].mn);
	t[x].mx = max(t[ls(x)].mx, t[rs(x)].mx);
}

inline void cover(int x, int y){
	t[x].tag = y;
	if(y) t[x].mn = t[x].l, t[x].mx = t[x].r;
	else t[x].mn = 1e9, t[x].mx = -1e9;
}

inline void down(int x){
	if(t[x].tag == -1) return;
	cover(ls(x), t[x].tag), cover(rs(x), t[x].tag);
	t[x].tag = -1;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		cover(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

void build(int x, int l, int r){
	t[x].mn = 1e9, t[x].mx = -1e9, t[x].tag = -1;
	if(l == r){
		t[x].l = t[x].r = dfn[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	t[x].l = min(t[ls(x)].l, t[rs(x)].l), t[x].r = max(t[ls(x)].r, t[rs(x)].r);
}

int opt, x, y;

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d%d", &n, &q);
	for(int i = 1;i < n;i++) scanf("%d%d%d", &get<1>(e[i]), &get<2>(e[i]), &get<0>(e[i]));
	sort(e + 1, e + n);
	m = n + n - 1;
	for(int i = 1;i <= m;i++) fa[i] = i;
	for(int i = 1;i < n;i++){
		int x = find(get<1>(e[i])), y = find(get<2>(e[i]));
		fa[x] = fa[y] = n + i;
		v[n + i].push_back(x), v[n + i].push_back(y);
		val[n + i] = get<0>(e[i]);
	}
	dfs(m);
	build(1, 1, n);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			modify(1, 1, n, x, y, 1);
		}else if(opt == 2){
			scanf("%d%d", &x, &y);
			modify(1, 1, n, x, y, 0);
		}else{
			scanf("%d", &x);
			if(t[1].mn != 1e9) x = lca(x, rnk[t[1].mn]);
			if(t[1].mx != -1e9) x = lca(x, rnk[t[1].mx]);
			printf("%d\n", val[x] ? val[x] : -1);
		}
	}
}