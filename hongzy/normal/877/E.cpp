#include <cstdio>
#include <vector>

const int MAXN = 200100;

int n, m; 
int s[MAXN];
std :: vector<int> G[MAXN];

int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
int top[MAXN], seg[MAXN], idx[MAXN], cnt;

void dfs1(int u, int f, int d) {
	fa[u] = f; dep[u] = d; sz[u] = 1;
	int mson = 0, id = 0;
	for(int i = 0, v; i < G[u].size(); i ++) {
		v = G[u][i];
		if(v != f) {
			dfs1(v, u, d + 1);
			if(mson < sz[v]) mson = sz[id = v];
			sz[u] += sz[v];
		}
	}
	son[u] = id;
}

void dfs2(int u, int t) {
	top[u] = t; seg[++ cnt] = u; idx[u] = cnt;
	if(!son[u]) return ;
	dfs2(son[u], t);
	for(int i = 0, v; i < G[u].size(); i ++) {
		v = G[u][i];
		if(!idx[v]) dfs2(v, v); 
	}
}

int sum[MAXN << 3];
bool tag[MAXN << 3];

void pushdown(int k, int l, int r) {
	if(tag[k]) {
		int mid = l + r >> 1;
		tag[k << 1] ^= 1;
		tag[k << 1 | 1] ^= 1;
		sum[k << 1] = mid - l + 1 - sum[k << 1];
		sum[k << 1 | 1] = r - mid - sum[k << 1 | 1];
		tag[k] = 0;
	}
}

void build(int k, int l, int r) {
	tag[k] = false;
	if(l == r) {
		sum[k] = s[ seg[l] ];
		return ;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

void rev(int k, int l, int r, int L, int R) {
	if(l > R || r < L) return ;
	if(L <= l && r <= R) {
		tag[k] ^= 1;
		sum[k] = r - l + 1 - sum[k];
		return ;
	} 
	int mid = l + r >> 1;
	pushdown(k, l, r);
	rev(k << 1, l, mid, L, R);
	rev(k << 1 | 1, mid + 1, r, L, R);
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
}

int query(int k, int l, int r, int L, int R) {
	if(l > R || r < L) return 0;
	if(L <= l && r <= R) return sum[k];
	int mid = l + r >> 1;
	pushdown(k, l, r);
	int ans1 = query(k << 1, l, mid, L, R);
	int ans2 = query(k << 1 | 1, mid + 1, r, L, R);
	sum[k] = sum[k << 1] + sum[k << 1 | 1];
	return ans1 + ans2;
}

int main() {
	scanf("%d", &n);
	for(int i = 2, v; i <= n; i ++) {
		scanf("%d", &v);
		G[i].push_back(v);
		G[v].push_back(i);
	}
	for(int i = 1; i <= n; i ++)
		scanf("%d", &s[i]);
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	
	scanf("%d", &m);
	char opt[30];
	for(int i = 1, u; i <= m; i ++) {
 		scanf("%s%d", opt, &u);
 		if(* opt == 'p') {
 			rev(1, 1, n, idx[u], idx[u] + sz[u] - 1);
		} else if(* opt == 'g') {
			printf("%d\n", query(1, 1, n, idx[u], idx[u] + sz[u] - 1));
		}
	}
	return 0;
}