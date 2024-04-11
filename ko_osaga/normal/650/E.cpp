#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
const int mod = 1e9 + 7;
const int MAXN = 500005;

pi edg[MAXN];
struct disj{
	int pa[MAXN], mark[MAXN];
	vector<pi> v[MAXN];
	void init(int n){
		iota(pa, pa + n, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		if(sz(v[p]) < sz(v[q])) swap(p, q);
		for(auto &i : v[q]) v[p].push_back(i);
		pa[q] = p; return 1;
	}
	void add_event(pi x, int idx){
		int p1 = find(x.first);
		int p2 = find(x.second);
		v[p1].emplace_back(idx, x.second);
		v[p2].emplace_back(idx, x.first);
		edg[idx] = x;
	}
	pi find_event(int x){
		x = find(x);
		while(sz(v[x]) && mark[v[x].back().first]) v[x].pop_back();
		assert(sz(v[x]));
		mark[v[x].back().first] = 1;
		return edg[v[x].back().first];
	}
}disj;

int n;
vector<pi> gph[MAXN];
int par[MAXN], pae[MAXN];

void dfs(int x, int p){
	for(auto [w, v] : gph[x]){
		if(v != p){
			par[v] = x;
			pae[v] = w;
			dfs(v, x);
		}
	}
	if(pae[x]){
		auto v = disj.find_event(x);
		printf("%d %d %d %d\n", x+1, 1+p, 1+v.first,1+ v.second);
		disj.uni(v.first, v.second);
	}
}

int main(){
	scanf("%d",&n);
	vector<pi> v1(n-1), v2(n-1);
	for(auto &i : v1){
		scanf("%d %d",&i.first,&i.second);i.first--; i.second--;
		if(i.first > i.second) swap(i.first, i.second);
	}
	for(auto &i : v2){
		scanf("%d %d",&i.first,&i.second);i.first--; i.second--;
		if(i.first > i.second) swap(i.first, i.second);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int ans = 0;
	for(auto &i : v1){
		bool good = !binary_search(v2.begin(), v2.end(), i);
		ans += good;
		gph[i.first].emplace_back(good, i.second);
		gph[i.second].emplace_back(good, i.first);
	}
	printf("%d\n", ans);
	disj.init(n);
	int idx = 0;
	for(auto &i : v2){
		bool good = !binary_search(v1.begin(), v1.end(), i);
		if(!good){
			disj.uni(i.first, i.second);
		}
		else{
			disj.add_event(i, ++idx);
		}
	}
	dfs(0, -1);
}