#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

const int MAXN = 100005;
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

int n, m, q;
vector<int> gph[100005];
int vis[100005];
vector<int> fars;

pi dfs(int x, int p){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i != p){
			auto l = dfs(i, x);
			l.first++;
			ret = max(ret, l);
		}
	}
	return ret;
}

int far[100005], tfar[100005];
vector<int> lis[100005];
vector<int> dis[100005];
vector<lint> ps[100005];
void dfs2(int x, int p, int d){
	far[x] = max(far[x], d);
	for(auto &i : gph[x]){
		if(i != p){
			dfs2(i, x, d+1);
		}
	}
}

double solve(int u, int v){
	if(disj.sz[u] > disj.sz[v]) swap(u, v);
	int th = max(tfar[u], tfar[v]);
	lint ret = 0;
	for(auto &i : dis[u]){
		int l = lower_bound(dis[v].begin(), dis[v].end(), th - i - 1) - dis[v].begin();
		ret += 1ll * th * l;
		ret += 1ll * (i + 1) * ((lint)dis[v].size() - l);
		ret += ps[v].back() - (l > 0 ? ps[v][l-1] : 0);
	}
	return (1.0 * ret) / (1ll * disj.sz[u] * disj.sz[v]);
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	disj.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
		disj.uni(s, e);
	}
	for(int i=1; i<=n; i++){
		if(disj.find(i) == i){
			auto l = dfs(i, -1).second;
			auto m = dfs(l, -1);
			dfs2(l, -1, 0);
			dfs2(m.second, -1, 0);
			tfar[i] = m.first;
		}
		lis[disj.find(i)].push_back(i);
	}
	for(int i=1; i<=n; i++){
		dis[disj.find(i)].push_back(far[i]);
	}
	for(int i=1; i<=n; i++) sort(dis[i].begin(), dis[i].end());
	for(int i=1; i<=n; i++){
		ps[i].resize(dis[i].size());
		lint sum = 0;
		for(int j=0; j<dis[i].size(); j++){
			sum += dis[i][j];
			ps[i][j] = sum;
		}
	}
	map<pi, double> mp;
	for(int i=0; i<q; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		u = disj.find(u);
		v = disj.find(v);
		if(u == v){
			puts("-1");
			continue;
		}
		if(u > v) swap(u, v);
		if(mp.find(pi(u, v)) == mp.end()) mp[pi(u, v)] = solve(u, v);
		printf("%.10f\n", mp[pi(u, v)]);
	}
}