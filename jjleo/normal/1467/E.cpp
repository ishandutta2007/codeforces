#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct Node{
	int son[2], sum;
}t[maxn * 50];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int cnt;

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

void modify(int x, int l, int r, int pos){
	if(l == r){
		t[x].sum++;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(!ls(x) ? ls(x) = ++cnt : ls(x), l, mid, pos);
	else modify(!rs(x) ? rs(x) = ++cnt : rs(x), mid + 1, r, pos);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(!x) return 0;
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1, sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum;
}


int n;
int a[maxn];
vector<int> V;
int rt[maxn];
int x, y;
vector<int> v[maxn];
int f[maxn], dfn[maxn], siz[maxn], tot;
int ans;

void dfs1(int i, int fa){
	dfn[i] = ++tot, siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs1(to, i);
		siz[i] += siz[to], f[i] += f[to];
	}
	f[i] += query(a[i], 1, n, dfn[i], dfn[i] + siz[i] - 1);
	modify(a[i], 1, n, dfn[i]);
}

void dfs2(int i, int fa){
	ans += !f[i];
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		f[to] += f[i] - f[to] - query(a[i], 1, n, dfn[to], dfn[to] + siz[to] - 1);
		f[to] += query(a[to], 1, n, 1, dfn[to] - 1);
		if(dfn[to] + siz[to] <= n) f[to] += query(a[to], 1, n, dfn[to] + siz[to], n);
		dfs2(to, i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), V.push_back(a[i]);
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for(int i = 1;i <= n;i++) a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	cnt = n;
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%d", ans);
}