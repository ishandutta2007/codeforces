#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

struct Node{
	LL sum[2];
	int cnt[2];
	bool rev;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	for(int i = 0;i <= 1;i++){
		t[x].sum[i] = t[ls(x)].sum[i] + t[rs(x)].sum[i];
		t[x].cnt[i] = t[ls(x)].cnt[i] + t[rs(x)].cnt[i];
	}
}

inline void reverse(int x){
	t[x].rev ^= 1;
	swap(t[x].sum[0], t[x].sum[1]), swap(t[x].cnt[0], t[x].cnt[1]);
}

inline void down(int x){
	if(!t[x].rev) return;
	t[x].rev = 0;
	reverse(ls(x)), reverse(rs(x));
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum[0] = d, t[x].cnt[0] = 1;
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

void Modify(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		reverse(x);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) Modify(ls(x), l, mid, ll, rr);
	if(mid < rr) Modify(rs(x), mid + 1, r, ll, rr);
	up(x);
}

int query(int x, int l, int r, int pos){
	if(l == r) return t[x].cnt[0];
	int mid = l + r >> 1;
	down(x);
	if(mid >= pos) return query(ls(x), l, mid, pos);
	return query(rs(x), mid + 1, r, pos);
}

int n;
vector<pair<int, int> > v[maxn]; 
int id[maxn];
int dep[maxn], fa[maxn], siz[maxn], son[maxn];
int dfn[maxn], rnk[maxn], top[maxn];
int cnt;
int opt, x, y;

void dfs1(int i){
	siz[i] = 1, dep[i] = dep[fa[i]] + 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first, co = v[i][j].second;
		if(to == fa[i]) continue;
		fa[to] = i, id[to] = co, dfs1(to);
		siz[i] += siz[to];
		if(siz[to] > siz[son[i]]) son[i] = to;
	}
}

void dfs2(int i, int t){
	top[i] = t, dfn[i] = ++cnt, rnk[dfn[i]] = i;
	if(!son[i]) return;
	dfs2(son[i], t);
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa[i] || to == son[i]) continue;
		dfs2(to, to);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back({y, i}), v[y].push_back({x, i});
	}
	dfs1(1), dfs2(1, 1);
	modify(1, 1, n, 1, 0);
	while(1){
		scanf("%d", &opt);
		if(opt == 3) return 0;
		if(opt == 1){
			scanf("%d", &x);
			modify(1, 1, n, dfn[x], id[x]);
			x = fa[x];
			while(x){
				Modify(1, 1, n, dfn[top[x]], dfn[x]);
				x = fa[top[x]];
			}
			printf("%lld\n", t[1].cnt[0] == t[1].cnt[1] ? t[1].sum[0] : 0), fflush(stdout);
		}else{
			if(t[1].cnt[0] ^ t[1].cnt[1]){
				puts("0"), fflush(stdout);
				continue;
			}
			vector<int> v;
			for(int i = 2;i <= n;i++) if(query(1, 1, n, dfn[i])) v.push_back(id[i]);
			sort(v.begin(), v.end());
			printf("%d ", v.size());
			for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
			puts(""), fflush(stdout);
		}
	}
}