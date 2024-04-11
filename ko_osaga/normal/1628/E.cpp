#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAXN = 600005;
const int MAXT = 1050000;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p > q) swap(p, q);
		if(p == q) return 0;
		pa[p] = q; return 1;
	}
}disj;

struct edges{ int s, e, x; };
int par[MAXN], dep[MAXN];
vector<int> gph[MAXN];
int din[MAXN], dout[MAXN], cost[MAXN], piv;

int spt[21][MAXN * 2];
int lg[MAXN * 2];

void dfs(int x){
	din[x] = ++piv;
	spt[0][piv] = x;
	for(auto &y : gph[x]){
		dep[y] = dep[x] + 1;
		dfs(y);
		spt[0][++piv] = x;
	}
	dout[x] = piv;
}

bool cmp(int x, int y){
	return dep[x] < dep[y];
}

int query(int s, int e){
	int l = lg[e - s + 1];
	return min(spt[l][s], spt[l][e - (1 << l) + 1], cmp);
}

bool in(int x, int y){
	return din[x] <= din[y] && dout[y] <= dout[x];
}

int lca(int x, int y){
	if(din[x] > din[y]) swap(x, y);
	if(in(x, y)) return x;
	return query(din[x], dout[y]);
}

int pathMax(int u, int v){
	return cost[lca(u, v)];
}

struct node{
	int l, r;
	int all; // const attribute

	int lazy;
	int mx, lval, rval;
}tree[MAXT];

void init(int s, int e, int p){
	tree[p].l = s;
	tree[p].r = e;
	tree[p].lazy = tree[p].mx = -1;
	tree[p].lval = tree[p].rval = -1;
	if(s == e){
		tree[p].all = -1;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, 2*p);
	init(m+1, e, 2*p+1);
	tree[p].all = max({tree[2*p].all, tree[2*p+1].all, pathMax(m, m + 1)});
}

void merge(node &a, node &b, node &c){
	c.mx = max({a.mx, b.mx});
	if(a.rval != -1 && b.lval != -1) c.mx = max(c.mx, pathMax(a.rval, b.lval));
	c.lval = (a.lval == -1 ? b.lval : a.lval);
	c.rval = (b.rval == -1 ? a.rval : b.rval);
}

void setByLazy(int p, int v){
	assert(v >= 0);
	tree[p].lazy = v;
	if(v == 0){
		tree[p].lval = tree[p].rval = -1;
		tree[p].mx = -1;
	}
	else{
		tree[p].lval = tree[p].l;
		tree[p].rval = tree[p].r;
			tree[p].mx = tree[p].all;
	}
}

void lazydown(int p){
	if(tree[p].lazy != -1){
		setByLazy(2*p, tree[p].lazy);
		setByLazy(2*p + 1, tree[p].lazy);
	}
	tree[p].lazy = -1;
}
void upd(int s, int e, int ps, int pe, int p, int v){
	if(e < ps || pe < s) return;
	if(s <= ps && pe <= e){
		tree[p].lazy = v;
		setByLazy(p, v);
		return;
	}
	lazydown(p);
	int pm = (ps + pe) / 2;
	upd(s, e, ps, pm, 2*p, v);
	upd(s, e, pm+1, pe, 2*p+1, v);
	merge(tree[2*p], tree[2*p+1], tree[p]);
}

bool isOn(int x, int s, int e, int p){
	if(s == e) return tree[p].lval == s;
	int m = (s + e) / 2;
	lazydown(p);
	if(x <= m) return isOn(x, s, m, 2*p);
	return isOn(x, m+1, e, 2*p+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<edges> ed(n - 1);
	for(int i = 0; i < n - 1; i++){
		int s, e, x; cin >> s >> e >> x;
		ed[i] = {s, e, x};
	}
	sort(all(ed), [&](const edges &a, const edges &b){
		return a.x < b.x;
	});
	disj.init(n + n);
	int vtx_num = n;
	fill(cost + 1, cost + n + 1, -1);
	for(auto &i : ed){
		int l = disj.find(i.s);
		int r = disj.find(i.e);
		vtx_num++;
		disj.uni(l, vtx_num);
		disj.uni(r, vtx_num);
		par[l] = vtx_num;
		par[r] = vtx_num;
		gph[vtx_num].push_back(l);
		gph[vtx_num].push_back(r);
		cost[vtx_num] = i.x;
	}
	dfs(2 * n - 1);
	for(int i=1; i<=piv; i++){
		lg[i] = lg[i - 1];
		if((2 << lg[i]) <= i) lg[i]++;
	}
	for(int i=1; i<21; i++){
		for(int j=1; j<=piv; j++){
			spt[i][j] = spt[i-1][j];
			if(j + (1<<(i-1)) <= piv) spt[i][j] = min(spt[i][j], spt[i-1][j + (1<<(i-1))], cmp);
		}
	}
	init(1, n, 1);
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int l, r; cin >> l >> r;
			upd(l, r, 1, n, 1, 1);
		}
		if(t == 2){
			int l, r; cin >> l >> r;
			upd(l, r, 1, n, 1, 0);
		}
		if(t == 3){
			int x; cin >> x;
			bool prv = isOn(x, 1, n, 1);
			if(prv == 0){
				upd(x, x, 1, n, 1, 1);
			}
			cout << tree[1].mx << "\n";
			if(prv == 0){
				upd(x, x, 1, n, 1, 0);
			}
		}
	}
}