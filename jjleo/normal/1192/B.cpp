#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

typedef long long LL;

struct Node{
	LL w, m, lm, mr, lmr, pl;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].w = max(t[ls(x)].w, t[rs(x)].w);
	t[x].m = max(t[ls(x)].m, t[rs(x)].m);
	t[x].lm = max(max(t[ls(x)].lm, t[rs(x)].lm), t[ls(x)].w + t[rs(x)].m);
	t[x].mr = max(max(t[ls(x)].mr, t[rs(x)].mr), t[ls(x)].m + t[rs(x)].w);
	t[x].lmr = max(max(t[ls(x)].lmr, t[rs(x)].lmr), max(t[ls(x)].lm + t[rs(x)].w, t[ls(x)].w + t[rs(x)].mr));
}

inline void add(int x, LL y){
	t[x].pl += y, t[x].w += y, t[x].m -= 2 * y;
	t[x].lm -= y, t[x].mr -= y;//lmmr lca 1 lmr 
}

inline void down(int x){
	if(t[x].pl) add(ls(x), t[x].pl), add(rs(x), t[x].pl), t[x].pl = 0;
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr) return add(x, d);
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

struct Edge{
	int x;
	LL y;
	int i;
};

vector<Edge> v[maxn];
int eid[maxn];
LL a[maxn], dep[maxn];
int bg[maxn], ed[maxn], id[maxn], cnt;

void dfs(int i, int fa){
	id[++cnt] = i, bg[i] = cnt;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j].x == fa) continue;
		a[v[i][j].x] = v[i][j].y, dep[v[i][j].x] = dep[i] + v[i][j].y, eid[v[i][j].i] = v[i][j].x;
		dfs(v[i][j].x, i);
		id[++cnt] = i;
	}
	ed[i] = cnt;
}

void build(int x, int l, int r){
	if(l == r){
		t[x].w = dep[id[l]], t[x].m = -2 * dep[id[l]];
		t[x].lm = t[x].mr = -dep[id[l]];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r), up(x);
}

int n, q;
LL w, lastans;
int x, y;
LL z;

int main(){
	scanf("%d%d%lld", &n, &q, &w);
	for(int i = 1;i < n;i++){
		scanf("%d%d%lld", &x, &y, &z);
		v[x].push_back((Edge){y, z, i}), v[y].push_back((Edge){x, z, i});
	} 
	dfs(1, 0), build(1, 1, cnt);
	while(q--){
		scanf("%d%lld", &x, &z);
		x = (x + lastans) % (n - 1) + 1;
		z = (z + lastans) % w;
		modify(1, 1, cnt, bg[eid[x]], ed[eid[x]], z - a[eid[x]]);
		a[eid[x]] = z;
		printf("%lld\n", lastans = t[1].lmr);
	}
}