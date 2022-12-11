#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 4e5 + 5;

int n, m, c[N];
vector<int> G[N];
int l[N], r[N], id[N], dfn;

void dfs(int u, int fa = 0) {
	l[u] = ++ dfn; id[dfn] = u;
	for(int & v : G[u]) 
		if(v ^ fa) dfs(v, u);
	r[u] = dfn;
}

LL s[N << 2];
int tag[N << 2];
void build(int rt, int l, int r) {
	if(l == r) {
		s[rt] = 1LL << c[id[l]];
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	s[rt] = s[rt << 1] | s[rt << 1 | 1]; 
}

void pushd(int rt) {
	if(tag[rt]) {
		tag[rt << 1] = tag[rt << 1 | 1] = tag[rt];
		s[rt << 1] = s[rt << 1 | 1] = 1LL << tag[rt];
		tag[rt] = 0;
	}
}

void reset(int rt, int l, int r, int L, int R, int c) {
	if(l > R || r < L) return ;
	if(L <= l && r <= R) {
		tag[rt] = c;
		s[rt] = 1LL << c;
		return ;
	}
	int mid = (l + r) >> 1; pushd(rt);
	reset(rt << 1, l, mid, L, R, c);
	reset(rt << 1 | 1, mid + 1, r, L, R, c);
	s[rt] = s[rt << 1] | s[rt << 1 | 1];
}

LL query(int rt, int l, int r, int L, int R) {
	if(l > R || r < L) return 0LL;
	if(L <= l && r <= R) return s[rt];
	int mid = (l + r) >> 1; pushd(rt);
	return query(rt << 1, l, mid, L, R) |
	query(rt << 1 | 1, mid + 1, r, L, R);
}

int popcount(LL x) {
	int ans = 0;
	for(; x; x &= x - 1) ans ++;
	return ans;	
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &c[i]);
	int u, v, op;
	for(int i = 1; i < n; i ++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1); build(1, 1, n);
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", &op, &u);
		if(op == 1) {
			scanf("%d", &v);
			reset(1, 1, n, l[u], r[u], v);
		}
		if(op == 2) {
			LL st = query(1, 1, n, l[u], r[u]);
			printf("%d\n", popcount(st));
		}
	} 
	return 0;
}