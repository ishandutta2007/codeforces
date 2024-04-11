#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 200005;

struct kek{
	int s, e, x;
}ed[MAXN];

struct edg{
	int pos, cst, idx;
};

vector<edg> gph[MAXN];
int par[MAXN], pae[MAXN];
lint dist_st[MAXN], dist_ed[MAXN];

void dijk(int src, lint *dist){
	dist[src] = 0;
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.emplace(0, src);
	while(sz(pq)){
		auto x = pq.top(); pq.pop();
		if(dist[x.second] != x.first) continue;
		for(auto &i : gph[x.second]){
			if(dist[i.pos] > x.first + i.cst){
				dist[i.pos] = x.first + i.cst;
				par[i.pos] = x.second;
				pae[i.pos] = i.idx;
				pq.emplace(dist[i.pos], i.pos);
			}
		}
	}
}

vector<pi> sptree[MAXN];
int topo[MAXN];
void dfs(int x){
	for(auto &[j, i] : sptree[x]){
		if(!topo[i]) topo[i] = topo[x];
		dfs(i);
	}
}

int IN_SP[MAXN];
vector<lint> add[MAXN], del[MAXN];
multiset<lint> ms;
int n, m, q;

int main(){
	memset(dist_st, 0x3f, sizeof(dist_st));
	memset(dist_ed, 0x3f, sizeof(dist_ed));
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=m; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		ed [i] = {s, e, x};
		gph[s].push_back({e, x, i});
		gph[e].push_back({s, x, i});
	}
	dijk(n, dist_ed);
	dijk(1, dist_st);
	vector<int> v;
	for(int i=2; i<=n; i++){
		sptree[par[i]].emplace_back(pae[i], i);
	}
	for(int i = n; i != 1; i = par[i]){
		v.push_back(i);
	}
	v.push_back(1);
	reverse(all(v));
	for(int i=0; i<sz(v); i++){
		topo[v[i]] = i + 1;
		if(i) IN_SP[pae[v[i]]] = i + 1;
	}
	dfs(1);
	for (int i=1; i<=n; i++) {
		for(auto &j : gph[i]){
			if(topo[i] < topo[j.pos] && pae[j.pos] != j.idx){
				int st = topo[i];
				int ed = topo[j.pos];
				lint ret = dist_st[i] + dist_ed[j.pos] + j.cst;
				add[st].push_back(ret);
				del[ed].push_back(ret);
			}
		}
	}
	vector<lint> tmp;
	for(int i=1; i<sz(v); i++){
		for (int j=0; j<del[i].size(); j++) {
			ms.erase(ms.find(del[i][j]));
		}
		for (int j=0; j<add[i].size(); j++) {
			ms.insert(add[i][j]);
		}
		if(ms.empty()) tmp.push_back(1e18);
		else tmp.push_back(*ms.begin());
	}
	while(q--){
		int x, v; scanf("%d %d",&x,&v);
		if(!IN_SP[x]){
			lint ans = min({dist_st[n],
			dist_st[ed[x].s] + v + dist_ed[ed[x].e],
			dist_st[ed[x].e] + v + dist_ed[ed[x].s]});
			if(ans > 1e17) ans = -1;
			printf("%lld\n", ans);
		}
		else{
			lint ans = min(dist_st[n] - ed[x].x + v, tmp[IN_SP[x] - 2]);
			if(ans > 1e17) ans = -1;
			printf("%lld\n", ans);
		}
	}
}