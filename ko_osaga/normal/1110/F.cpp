#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXT = 1050000;
using lint = long long;
using pi = pair<int, int>;
int din[MAXN], dout[MAXN];

struct seg{
	lint tree[MAXT];
	int lim;
	void init(int n){
		memset(tree, 0x3f, sizeof(tree));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, lint v){
		x += lim;
		tree[x] = min(tree[x], v);
		while(x > 1){
			x >>= 1;
			tree[x] = min(tree[2*x], tree[2*x+1]);
		}
	}
	lint query(int s, int e){
		s += lim;
		e += lim;
		lint ret = 1e18;
		while(s < e){
			if(s%2 == 1) ret = min(ret, tree[s++]);
			if(e%2 == 0) ret = min(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = min(ret, tree[s]);
		return ret;
	}
}seg;

int n, q;
vector<pi> gph[MAXN];
int par[19][MAXN], dep[MAXN], piv;
lint len[MAXN], L[19][MAXN], R[19][MAXN];

int getlca(int s, int e){
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<19; i++){
		if((dx >> i) & 1) e = par[i][e];
	}
	for(int i=18; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) return par[0][s];
	return s;
}

bool in(int s, int e){
	return din[s] <= din[e] && dout[e] <= dout[s];
}

lint subtreeQuery(int v, int l, int r){
	l = max(l, din[v]);
	r = min(r, dout[v]);
	return seg.query(l, r);
}

lint LPathQuery(int x, int c){
	lint ret = 1e18;
	for(int i=0; i<19; i++){
		if((c >> i) & 1){
			ret = min(ret, L[i][x]);
			x = par[i][x];
		}
	}
	return ret;
}

lint RPathQuery(int x, int c){
	lint ret = 1e18;
	for(int i=0; i<19; i++){
		if((c >> i) & 1){
			ret = min(ret, R[i][x]);
			x = par[i][x];
		}
	}
	return ret;
}
void dfs(int x){
	din[x] = ++piv;
	for(auto &i : gph[x]){
		dep[i.second] = dep[x] + 1;
		len[i.second] = len[x] + i.first;
		dfs(i.second);
	}
	dout[x] = piv;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=2; i<=n; i++){
		int p, w; scanf("%d %d",&p,&w);
		par[0][i] = p;
		gph[p].emplace_back(w, i);
	}
	seg.init(n);
	dfs(1);
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	vector<int> bs;
	for(int i=1; i<=n; i++){
		if(gph[i].empty()) {
			bs.push_back(i);
			seg.add(i, len[i]);
		}
	}
	for(int i=2; i<=n; i++){
		L[0][i] = seg.query(din[par[0][i]], din[i] - 1) - 2 * len[par[0][i]];
		R[0][i] = seg.query(dout[i] + 1, dout[par[0][i]]) - 2 * len[par[0][i]];
	}
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++){
			L[i][j] = min(L[i-1][j], L[i-1][par[i-1][j]]);
			R[i][j] = min(R[i-1][j], R[i-1][par[i-1][j]]);
		}
	}
	auto query_inside = [&](int v, int l, int r){
		lint ret = 1e18;
		ret = min(ret, subtreeQuery(v, l, r) - len[v]);
		int lca = getlca(l, r);
		ret = min(ret, subtreeQuery(lca, l, r) - 2 * len[lca] + len[v]);
		{
			int tmp = getlca(v, l);
			if(tmp != v) ret = min(ret, LPathQuery(v, dep[v] - dep[tmp] - 1) + len[v]);
			ret = min(ret, subtreeQuery(tmp, l, r) - 2 * len[tmp] + len[v]);
		}
		{
			int tmp = getlca(v, r);
			if(tmp != v) ret = min(ret, RPathQuery(v, dep[v] - dep[tmp] - 1) + len[v]);
			ret = min(ret, subtreeQuery(tmp, l, r) - 2 * len[tmp] + len[v]);
		}
		return ret;
	};
	auto dist = [&](int x, int y){
		return len[x] + len[y] - 2 * len[getlca(x, y)];
	};
	while(q--){
		int v, l, r;
		scanf("%d %d %d",&v,&l,&r);
		l = *lower_bound(bs.begin(), bs.end(), l);
		r = *prev(upper_bound(bs.begin(), bs.end(), r));
		int lca = getlca(l, r);
		if(!in(lca, v)){
			printf("%lld\n", query_inside(lca, l, r) + dist(v, lca));
		}
		else if(r < v){
			int nl = getlca(r, v);
			printf("%lld\n", query_inside(nl, l, r) + dist(nl, v));
		}
		else if(v < l){
			int nl = getlca(l, v);
			printf("%lld\n", query_inside(nl, l, r) + dist(nl, v));
		}
		else{
			printf("%lld\n", query_inside(v, l, r));
		}
	}
}