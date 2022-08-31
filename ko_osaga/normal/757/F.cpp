#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 200010;

namespace dtree{
	vector <int> E[MAXN];
	vector <int> RE[MAXN], rdom[MAXN];

	int S[MAXN], RS[MAXN], cs;
	int par[MAXN], val[MAXN];
	int sdom[MAXN], rp[MAXN];
	int dom[MAXN];

	void clear(int n) {
		cs = 0;
		for(int i=0;i<=n;i++) {
			par[i] = val[i] = sdom[i] = rp[i] = dom[i] = S[i] = RS[i] = 0;
			E[i].clear(); RE[i].clear(); rdom[i].clear();
		}
	}

	void add_edge(int x, int y) {
		E[x].push_back(y);
	}

	int Find(int x, int c = 0) {
		if(par[x] == x) return c ? -1 : x;
		int p = Find(par[x], 1);
		if(p == -1) return c ? par[x] : val[x];
		if(sdom[val[x]] > sdom[val[par[x]]]) val[x] = val[par[x]];
		par[x] = p;
		return c ? p : val[x];
	}

	void Union(int x, int y) {
		par[x] = y;
	}

	void dfs(int x) {
		RS[ S[x] = ++cs ] = x;
		par[cs] = sdom[cs] = val[cs] = cs;
		for(int e : E[x]) {
			if(S[e] == 0) dfs(e), rp[S[e]] = S[x];
			RE[S[e]].push_back(S[x]);
		}
	}

	int solve(int s, int *up) { // Calculate idoms
		dfs(s);
		for(int i=cs;i;i--) {
			for(int e : RE[i]) sdom[i] = min(sdom[i], sdom[Find(e)]);
			if(i > 1) rdom[sdom[i]].push_back(i);
			for(int e : rdom[i]) {
				int p = Find(e);
				if(sdom[p] == i) dom[e] = i;
				else dom[e] = p;
			}
			if(i > 1) Union(i, rp[i]);
		}
		for(int i=2;i<=cs;i++) if(sdom[i] != dom[i]) dom[i] = dom[dom[i]];
		for(int i=2;i<=cs;i++) {
			up[RS[i]] = RS[dom[i]];
		}
		return cs;
	}
};

vector<pi> gph[MAXN];
vector<int> tr[MAXN];
int par[MAXN], sz[MAXN];
lint dis[MAXN];

void dfs(int x){
	sz[x] = 1;
	for(auto &i : tr[x]){
		dfs(i);
		sz[x] += sz[i];
	}
}

int main(){
	int n, m, r;
	scanf("%d %d %d",&n,&m,&r);
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		gph[s].push_back(pi(x, e));
		gph[e].push_back(pi(x, s));
	}
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(pi(0, r));
	dis[r] = 0;
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(dis[x.second] != x.first) continue;
		for(auto &i : gph[x.second]){
			if(dis[i.second] > dis[x.second] + i.first){
				dis[i.second] = dis[x.second] + i.first;
				pq.push(pi(dis[i.second], i.second));
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(dis[j.second] == dis[i] + j.first){
				dtree::add_edge(i, j.second);
			}
		}
	}
	dtree::solve(r, par);
	for(int i=1; i<=n; i++){
		if(par[i]) tr[par[i]].push_back(i);
	}
	dfs(r);
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(i != r) ans = max(ans, sz[i]);
	}
	cout << ans;
}