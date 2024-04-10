#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

//a:) b:(
struct node{
	int a, b, d, l1, l2, r1, r2;
};

struct Node{
	int rev;
	node a, b;
}t[maxn * 12];// 3 * 4 = 12 <<6 

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1) 

inline void merge(node &x, node &l, node &r){
	x.a = l.a + max(0, r.a - l.b);
	x.b = r.b + max(0, l.b - r.a);
	x.d = max(max(l.d, r.d), max(l.r1 + r.l2, l.r2 + r.l1));
	x.l1 = max(l.l1, max(r.l1 + l.a - l.b, r.l2 + l.a + l.b));
	x.l2 = max(l.l2, r.l2 + l.b - l.a);
	x.r1 = max(r.r1, max(l.r1 + r.b - r.a, l.r2 + r.a + r.b));
	x.r2 = max(r.r2, l.r2 + r.a - r.b);
}

inline void up(int x){
	merge(t[x].a, t[ls(x)].a, t[rs(x)].a);
	merge(t[x].b, t[ls(x)].b, t[rs(x)].b);	
}

inline void reverse(int x){
	t[x].rev ^= 1;
	swap(t[x].a, t[x].b);
}

inline void down(int x){
	if(t[x].rev){
		t[x].rev = false;
		reverse(ls(x)), reverse(rs(x));
	} 
}

void modify(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		reverse(x);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr);
	up(x);
}

vector<pair<int, int> > v[maxn];
int dfn[maxn * 3], cnt;
int val[maxn];
int a[maxn], id[maxn];
int st[maxn], ed[maxn];

void dfs(int i, int fa){
	dfn[st[i] = ++cnt] = -1, dfn[++cnt] = i;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, k = v[i][j].second; 
		if(to == fa) continue;
		val[to] = val[i] ^ a[k], id[k] = to;
		dfs(to, i);
	} 
	dfn[ed[i] = ++cnt] = -2;
}

inline void init(node &x, int i, int j){
	x.l1 = x.l2 = x.r1 = x.r2 = -1e9;
	if(dfn[i] == -1){
		x.b = 1;
	}else if(dfn[i] == -2){
		x.a = 1;
	}else if(val[dfn[i]] == j){
		x.l1 = x.l2 = x.r1 = x.r2 = 0;
	}
}

void build(int x, int l, int r){
	if(l == r){
		init(t[x].a, l, 0), init(t[x].b, l, 1);
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, m;
int x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d%d", &x, &y, &a[i]);
		v[x].push_back({y, i}), v[y].push_back({x, i});
	}
	dfs(1, 0);
	build(1, 1, cnt);
	scanf("%d", &m);
	while(m--){
		scanf("%d", &x);
		modify(1, 1, cnt, st[id[x]], ed[id[x]]);
		printf("%d\n", max(t[1].a.d, t[1].b.d));
	}
}