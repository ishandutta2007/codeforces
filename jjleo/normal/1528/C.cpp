#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int T, n;
vector<int> v[maxn]; 
int dep[maxn], fa[maxn], siz[maxn], son[maxn];
int dfn[maxn], rnk[maxn], top[maxn];
int cnt;

void dfs1(int i){
	siz[i] = 1, dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i]) continue;
		fa[to] = i, dfs1(to);
		siz[i] += siz[to];
		if(siz[to] > siz[son[i]]) son[i] = to;
	}
}

void dfs2(int i, int t){
	top[i] = t, dfn[i] = ++cnt, rnk[dfn[i]] = i;
	if(!son[i]) return;
	dfs2(son[i], t);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i] || to == son[i]) continue;
		dfs2(to, to);
	}
}

struct SegmentTree{
	struct Node{
		int sum, tag;
	}t[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		t[x].sum = max(t[ls(x)].sum ,t[rs(x)].sum);
	}
	
	inline void add(int x, int y){
		t[x].sum += y;
		t[x].tag += y;
	}
	
	inline void down(int x){
		if(!t[x].tag) return;
		add(ls(x), t[x].tag), add(rs(x), t[x].tag);
		t[x].tag = 0;
	}
	
	void modify(int x, int l, int r, int ll, int rr, int d){
		if(ll <= l && r <= rr){
			add(x, d);
			return;
		}
		int mid = l + r >> 1;
		down(x);
		if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
		if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return t[x].sum;
		int mid = l + r >> 1, sum = 0;
		down(x);
		if(mid >= ll) sum = max(sum, query(ls(x), l, mid, ll, rr));
		if(mid < rr) sum = max(sum, query(rs(x), mid + 1, r, ll, rr));
		return sum;
	}
	
	void build(int x, int l, int r){
		t[x].sum = t[x].tag = 0;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
	
	void Add(int x, int y, int d){
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			modify(1, 1, n, dfn[top[x]], dfn[x], d);
			x = fa[top[x]];
		}
		if(dfn[x] > dfn[y]) swap(x, y);
		modify(1, 1, n, dfn[x], dfn[y], d);
	}
	
	int Query(int x, int y){
		int ans = 0;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			ans += query(1, 1, n, dfn[top[x]], dfn[x]);
			x = fa[top[x]];
		}
		if(dfn[x] > dfn[y]) swap(x, y);
		ans += query(1, 1, n, dfn[x], dfn[y]);
		return ans;
	}
}t[2];

int x;
vector<int> w[maxn];
int ans;

void dfs(int i){
	int x = t[1].Query(1, i);
	if(x) t[0].Add(1, x, -1), t[1].Add(x, x, -x);
	t[0].Add(1, i, 1), t[1].Add(i, i, i);
	ans = max(ans, t[0].t[1].sum);
	for(int j = 0;j < w[i].size();j++){
		dfs(w[i][j]);
	}
	if(x) t[0].Add(1, x, 1), t[1].Add(x, x, x);
	t[0].Add(1, i, -1), t[1].Add(i, i, -i);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			v[i].clear(), w[i].clear();
			fa[i] = son[i] = 0;
		}
		cnt = 0;
		for(int i = 2;i <= n;i++) scanf("%d", &x), w[x].push_back(i);
		for(int i = 2;i <= n;i++) scanf("%d", &x), v[x].push_back(i);
		dfs1(1), dfs2(1, 1);
		t[0].build(1, 1, n), t[1].build(1, 1, n);
		ans = 0, dfs(1);
		printf("%d\n", ans);
	}
}