#include <bits/stdc++.h>
#define maxn 400086
using namespace std;

typedef long long LL;

struct Node{
	LL sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum | t[rs(x)].sum;
}

inline void col(int x, LL d){
	t[x].sum = t[x].tag = d;
}

inline void down(int x){
	if(t[x].tag){
		col(ls(x), t[x].tag), col(rs(x), t[x].tag);
		t[x].tag = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr){
		col(x, d);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	down(x);
	int mid = l + r >> 1;
	LL sum = 0;
	if(mid >= ll) sum |= query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum |= query(rs(x), mid + 1, r, ll, rr);
	return sum;
}

int dfn[maxn], rnk[maxn], siz[maxn], cnt;
vector<int> v[maxn];

void dfs(int i, int fa){
	siz[i] = 1, dfn[i] = ++cnt, rnk[dfn[i]] = i;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		siz[i] += siz[to];
	}
}

int c[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = 1ll << c[rnk[l]];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, m;
int x, y;
int opt;


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	build(1, 1, n);
	while(m--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			modify(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, 1ll << y);
		}else{
			scanf("%d", &x);
			LL sum = query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1);
			y = 0;
			while(sum){
				if(sum & 1) y++;
				sum >>= 1;
			}
			printf("%d\n", y);
		}
	}
}