#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 500005;
const int mod = 1e9 + 7;
typedef pair<int, int> pi;

struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;

struct edg{
	int s, e, x, t;
	bool operator<(const edg &e)const{
		return pi(x, t) < pi(e.x, e.t);
	}
}e[MAXN], f[MAXN];

vector<pi> gph[MAXN];
int pa[19][MAXN], dp[19][MAXN], dep[MAXN];
int din[MAXN], dout[MAXN], piv;

bool in(int s, int e){ return din[s] <= din[e] && dout[e] <= dout[s]; }

void dfs(int x, int p){
	din[x] = ++piv;
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		dep[i.second] = dep[x] + 1;
		dp[0][i.second] = i.first;
		pa[0][i.second] = x;
		dfs(i.second, x);
	}
	dout[x] = piv;
}

int lca(int s, int e){
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<19; i++){
		if((dx >> i) & 1){
			e = pa[i][e];
		}
	}
	for(int i=18; i>=0; i--){
		if(pa[i][s] != pa[i][e]){
			s = pa[i][s], e = pa[i][e];
		}
	}
	if(s != e) return pa[0][s];
	return s;
}
int query(int s, int e){
	int ans = 0;
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<19; i++){
		if((dx >> i) & 1){
			ans = max(ans, dp[i][e]);
			e = pa[i][e];
		}
	}
	for(int i=18; i>=0; i--){
		if(pa[i][s] != pa[i][e]){
			ans = max({ans, dp[i][s], dp[i][e]});
			s = pa[i][s], e = pa[i][e];
		}
	}
	if(s != e) ans = max({ans, dp[0][s], dp[0][e]});
	return ans;
}

int n, m;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++){
		scanf("%d %d %d",&f[i].s,&f[i].e,&f[i].x);
		e[i-1] = f[i];
	}
	sort(e, e+m);
	disj.init(n);
	for(int i=0; i<m; i++){
		if(disj.uni(e[i].s, e[i].e)){
			gph[e[i].s].push_back(pi(e[i].x, e[i].e));
			gph[e[i].e].push_back(pi(e[i].x, e[i].s));
		}
	}
	disj.init(n);
	dfs(1, 0);
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++){
			pa[i][j] = pa[i-1][pa[i-1][j]];
			dp[i][j] = max(dp[i-1][j], dp[i-1][pa[i-1][j]]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		vector<int> v(k);
		vector<int> w;
		bool ok = 1;
		for(int i=0; i<k; i++){
			scanf("%d",&v[i]);
			w.push_back(f[v[i]].s);
			w.push_back(f[v[i]].e);
		}
		sort(w.begin(), w.end(), [&](const int &a, const int &b){
			return din[a] < din[b];
		});
		w.resize(unique(w.begin(), w.end()) - w.begin());
		int n = w.size();
		for(int i=1; i<n; i++){
			w.push_back(lca(w[i], w[i-1]));
		}
		sort(w.begin(), w.end(), [&](const int &a, const int &b){
			return din[a] < din[b];
		});
		w.resize(unique(w.begin(), w.end()) - w.begin());
		stack<int> stk;
		stk.push(w[0]);
		vector<edg> elice;
		for(auto &i : v){
			elice.push_back({f[i].s, f[i].e, f[i].x, -1});
		}
		for(int i=1; i<w.size(); i++){
			while(!in(stk.top(), w[i])) stk.pop();
			int l = query(stk.top(), w[i]);
			elice.push_back({stk.top(), w[i], l, 1});
			stk.push(w[i]);
		}
		sort(elice.begin(), elice.end());
		int cnt = 0;
		for(auto &i : elice){
			if(disj.uni(i.s, i.e) && i.t == -1) cnt++;
		}
		puts(cnt == v.size() ? "YES" : "NO");
		for(auto &i : w) disj.pa[i] = i;
	}
}