#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

int n, m, q, n0;

multiset<int> st[maxn];
int son[maxn], rnk[maxn], top[maxn], siz[maxn], fa[maxn], dep[maxn];
vector<int> v1[maxn], v2[maxn];
int dfn[maxn], low[maxn], cnt;
int sk[maxn], Top;
int val[maxn];

void dfs(int i){
	dfn[i] = low[i] = ++cnt, sk[++Top] = i;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j];
		if(!dfn[to]){
			dfs(to);
			low[i] = min(low[i], low[to]);
			if(dfn[i] == low[to]){
				v2[++n0].push_back(i), v2[i].push_back(n0);
				while(sk[Top + 1] != to) v2[n0].push_back(sk[Top]), v2[sk[Top--]].push_back(n0);
				//to i  
			} 
		}else{
			low[i] = min(low[i], dfn[to]);
		}
	}
}


struct Node{
	int sum;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
}

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = val[rnk[l]];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

inline void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x); 
}

inline int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1, sum = 1e9;
	if(mid >= ll) sum = min(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = min(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

void dfs1(int i){
	son[i] = -1, siz[i] = 1;
	if(i <= n) st[fa[i]].insert(val[i]);
	else val[i] = 1e9;
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j]; 
		if(!dep[to]){
			dep[to] = dep[i] + 1, fa[to] = i;
			dfs1(to);
			siz[i] += siz[to];
			if(son[i] == -1 || siz[to] > siz[son[i]]) son[i] = to;
		}
	}
	if(i > n) val[i] = *(st[i].begin());
}

void dfs2(int i, int t){
	top[i] = t, dfn[i] = ++cnt, rnk[cnt] = i;
	if(son[i] == -1) return;
	dfs2(son[i], t);
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j];
		if(to != son[i] && to != fa[i]) dfs2(to, to);
	}
}

inline int Query(int x, int y){
	int ans = 1e9;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = min(ans, query(1, 1, n0, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if(dfn[x] > dfn[y]) swap(x, y);
	ans = min(ans, query(1, 1, n0, dfn[x], dfn[y]));
	if(x > n && fa[x]) ans = min(ans, val[fa[x]]);//debug:lca 
	return ans;
}



inline void Modify(int x, int y){
	modify(1, 1, n0, dfn[x], y);
	st[fa[x]].erase(st[fa[x]].find(val[x])), st[fa[x]].insert(val[x] = y);//debug:val 
	modify(1, 1, n0, dfn[fa[x]], *(st[fa[x]].begin()));
}

int x, y;
char s[5];

int main(){
	scanf("%d%d%d", &n, &m, &q), n0 = n;
	for(int i = 1;i <= n;i++) scanf("%d", &val[i]);
	while(m--){
		scanf("%d%d", &x, &y);
		v1[x].push_back(y), v1[y].push_back(x);
	}
	dfs(1), cnt = 0;
	
	dep[n0] = 1, dfs1(n0), dfs2(n0, n0);
	build(1, 1, n0);
	//for(int i = 1;i <= n0;i++) printf("%d ", val[i]);puts("--");
	while(q--){
		scanf("%s%d%d", s, &x, &y);
		if(s[0] == 'C'){
			Modify(x, y);
		}else{
			printf("%d\n", Query(x, y));
		}
	}
}