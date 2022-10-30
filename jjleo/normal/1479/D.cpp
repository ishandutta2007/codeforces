#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

int n, m, sn;
vector<int> v[maxn];
int x, y, l, r;
int eu[maxn], st[maxn], ed[maxn], cnt;
int fa[maxn][25], lg[maxn], dep[maxn];

void dfs(int i){
	eu[st[i] = ++cnt] = i, dep[i] = dep[fa[i][0]] + 1;
	for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa[i][0]) continue;
		fa[to][0] = i;
		dfs(to);
	}
	eu[ed[i] = ++cnt] = i;
}

inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	if(x == y) return x;
	for(int i = 20;~i;i--) if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

struct query{
	int l, r, pos, i, lca, L, R;
}q[maxn];

inline bool cmp(query x, query y){
	return x.pos ^ y.pos ? x.pos < y.pos : x.pos & 1 ? x.r < y.r : x.r > y.r;
}

int a[maxn], ans[maxn];
bool tag[600][600];
int tot[maxn];

void modify(int x){
	int id = a[x] / sn;
	tag[id][a[x] - id * sn] ^= 1;
	if(tag[id][a[x] - id * sn]) tot[id]++;
	else tot[id]--;
}

int main(){
	scanf("%d%d", &n, &m);
	sn = (int)sqrt(n << 1);
	for(int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), a[i]--;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d%d", &x, &y, &l, &r), l--, r--;
		if(st[x] > st[y]) swap(x, y);
		if(ed[x] >= ed[y]) q[i] = (query){st[x], st[y], st[x] / sn + 1, i, 0, l, r};
		else q[i] = (query){ed[x], st[y], ed[x] / sn + 1, i, lca(x, y), l, r};
	}
	sort(q + 1, q + 1 + m, cmp);
	int l = 1, r = 1;
	sn = (int)sqrt(n), modify(eu[1]);
	memset(ans, -1, sizeof(ans));
	for(int i = 1;i <= m;i++){
		while(l > q[i].l) modify(eu[--l]);
		while(r < q[i].r) modify(eu[++r]);
		while(l < q[i].l) modify(eu[l++]);
		while(r > q[i].r) modify(eu[r--]);
		if(q[i].lca) modify(q[i].lca);
		int L = q[i].L / sn, R = q[i].R / sn;
		if(L == R){
			for(int j = q[i].L;j <= q[i].R && ans[q[i].i] == -1;j++){
				if(tag[L][j - L * sn]) ans[q[i].i] = j;
			}
		}else{
			for(int j = q[i].L;j / sn == L && ans[q[i].i] == -1;j++){
				if(tag[L][j - L * sn]) ans[q[i].i] = j;
			}
			for(int j = q[i].R;j / sn == R && ans[q[i].i] == -1;j--){
				if(tag[R][j - R * sn]) ans[q[i].i] = j;
			}
			for(int j = L + 1;j < R && ans[q[i].i] == -1;j++){
				if(!tot[j]) continue;
				for(int k = j * sn;k / sn == j && ans[q[i].i] == -1;k++){
					if(tag[j][k - j * sn]) ans[q[i].i] = k;
				}
			}
		}
		if(q[i].lca) modify(q[i].lca);
	}
	for(int i = 1;i <= m;i++) printf("%d\n", ans[i] == -1 ? -1 : ans[i] + 1);
}