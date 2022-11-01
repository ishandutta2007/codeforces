#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

struct Node{
	int sum, id;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = max(t[ls(x)].sum,  t[rs(x)].sum);
	t[x].id = t[x].sum == t[ls(x)].sum ? t[ls(x)].id : t[rs(x)].id;
}

void modify(int x, int l, int r, int pos){
	if(l == r){
		t[x].sum = 0;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos);
	else modify(rs(x), mid + 1, r, pos);
	up(x);
}

pair<int, int> query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return {t[x].sum, t[x].id};
	int mid = l + r >> 1;
	pair<int, int> a = {-1, 0}, b = {-1, 0};
	if(mid >= ll) a = query(ls(x), l, mid, ll, rr);
	if(mid < rr) b = query(rs(x), mid + 1, r, ll, rr);
	return {max(a.first, b.first), a.first > b.first ? a.second : b.second};
}

int n, m, q;
int p[maxn];
int x[maxn], y[maxn];
int a[maxn], b[maxn];
bool vis[maxn];
int tim[maxn];
vector<int> v[maxn];

int cnt;
int fa[maxn];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int dfn[maxn], rnk[maxn], siz[maxn], tot;
int f[maxn][25];

void dfs(int i){
	//printf("%d--\n", i);
	rnk[dfn[i] = ++tot] = i, siz[i] = 1;
	for(int j = 1;j <= 20;j++) f[i][j] = f[f[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		f[to][0] = i, dfs(to);
		siz[i] += siz[to];
	}
	
}

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = p[rnk[l]], t[x].id = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int main(){
	scanf("%d%d%d", &n, &m, &q), cnt = n;
	memset(p, -1, sizeof(p));
	for(int i = 1;i <= n;i++) scanf("%d", &p[i]);
	for(int i = 1;i <= m;i++) scanf("%d%d", &a[i], &b[i]);
	for(int i = 1;i <= q;i++){
		scanf("%d%d", &x[i], &y[i]);
		if(x[i] == 2) vis[y[i]] = true;
	}
	for(int i = 1;i < maxn;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		if(vis[i]) continue;
		int x = find(a[i]), y = find(b[i]);
		if(x == y) continue;
		tim[fa[x] = fa[y] = ++cnt] = q + 1;
		v[cnt].push_back(x), v[cnt].push_back(y);
	}
	
	for(int i = q;i;i--){
		if(x[i] == 1) continue;
		int X = find(a[y[i]]), Y = find(b[y[i]]);
		if(X == Y) continue;
		tim[fa[X] = fa[Y] = ++cnt] = i;
		v[cnt].push_back(X), v[cnt].push_back(Y);
	}
	for(int i = 1;i <= cnt;i++){
		int x = find(i);
		if(!siz[x]) dfs(x);
	}
	build(1, 1, cnt);
	for(int i = 1;i <= q;i++){
		if(x[i] == 2) continue;
		int x = y[i];
		for(int j = 20;~j;j--) if(tim[f[x][j]] >= i) x = f[x][j];
		//printf("%d %d %d--\n", x, dfn[x], dfn[x] + siz[x] - 1);
		pair<int, int> p = query(1, 1, cnt, dfn[x], dfn[x] + siz[x] - 1);
		printf("%d\n", p.first);
		modify(1, 1, cnt, p.second);
	}
}