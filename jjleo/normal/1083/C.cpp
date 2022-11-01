#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

vector<int> v[maxn];
int eu[maxn << 1], tot1, pos[maxn], dep[maxn], dfn[maxn], tot2;
int st[maxn << 1][25], lg[maxn << 1];

void dfs(int i){
	eu[pos[i] = ++tot1] = i, dfn[i] = ++tot2;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dep[to] = dep[i] + 1, dfs(to);
		eu[++tot1] = i;
	}
}

inline void init(){
	for(int i = 2;i <= tot1;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	for(int i = 1;i <= tot1;i++) st[i][0] = eu[i];
	for(int j = 1;j <= 20;j++){
		for(int i = 1;i + (1 << j) - 1 <= tot1;i++){
			st[i][j] = pos[st[i][j - 1]] < pos[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1]; 
		}
	}
}

inline int lca(int x, int y){
	if(pos[x] > pos[y]) swap(x, y);
	return pos[st[pos[x]][lg[pos[y] - pos[x]]]] < pos[st[pos[y] - (1 << lg[pos[y] - pos[x]]) + 1][lg[pos[y] - pos[x]]]] ? st[pos[x]][lg[pos[y] - pos[x]]] : st[pos[y] - (1 << lg[pos[y] - pos[x]]) + 1][lg[pos[y] - pos[x]]];
}

inline int dis(int x, int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int n, q;
int a[maxn], b[maxn];
int opt, x, y;

inline pair<int, int> merge(int a, int b, int c){
	int ab = dis(a, b), ac = dis(a, c), bc = dis(b, c);
	if(ab + ac == bc) return {b, c};
	if(ac + bc == ab) return {a, b};
	if(bc + ab == ac) return {a, c};
	return {0, 0};
}

inline pair<int, int> up(pair<int, int> a, pair<int, int> b){
	if(!a.first || !b.first) return {0, 0};
	a = merge(a.first, a.second, b.first);
	if(!a.first) return a;
	a = merge(a.first, a.second, b.second);
	return a;
}

pair<int, int> p[maxn << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void build(int x, int l, int r){
	if(l == r){
		p[x] = {b[l], b[l]};
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	p[x] = up(p[ls(x)], p[rs(x)]);
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		p[x] = {d, d};
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	p[x] = up(p[ls(x)], p[rs(x)]);
}

int query(){
	if(p[1].first) return n;
	int l = 1, r = n, mid, x = 1;
	pair<int, int> t = {0, 0};
	while(l < r){
		mid = l + r >> 1;
		if(!t.first){
			if(!p[ls(x)].first) r = mid, x = ls(x);
			else t = p[ls(x)], l = mid + 1, x = rs(x); 
			continue;
		}
		pair<int, int> tt = up(t, p[ls(x)]);
		if(!tt.first) r = mid, x = ls(x);
		else t = tt, l = mid + 1, x = rs(x);
	}
	return l - 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[++a[i]] = i;
	for(int i = 2;i <= n;i++){
		scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1);
	init();
	build(1, 1, n);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			swap(a[x], a[y]);
			modify(1, 1, n, a[x], x), modify(1, 1, n, a[y], y);
		}else printf("%d\n", query());
	} 
}