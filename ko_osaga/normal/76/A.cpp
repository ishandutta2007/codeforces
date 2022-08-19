#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct edg{
	int s, e, x, y;
	bool operator<(const edg &e)const{
		return pi(x, y) < pi(e.x, e.y);
	}
}e[50005];

int n, m, p, q;

vector<pi> gph[205];
int par[222], pae[222], dep[222];;

void dfs(int x, int p){
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		par[i.second] = x;
		pae[i.second] = i.first;
		dep[i.second] = dep[x] + 1;
		dfs(i.second, x);
	}
}

void rem_edge(int s, int e){
	auto it = gph[s].begin();
	while(it->second != e) it++;
	gph[s].erase(it);
	it = gph[e].begin();
	while(it->second != s) it++;
	gph[e].erase(it);
}

struct disj{
	int pa[222];
	void init(int n){
		for(int i=1; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int main(){
	cin >> n >> m >> p >> q;
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d",&e[i].s, &e[i].e, &e[i].x, &e[i].y);
	}
	sort(e, e+m);
	disj.init(n);
	lint ret = 5e18;
	int cnt = 0;
	for(int i=0; i<m; i++){
		if(disj.uni(e[i].s, e[i].e)){
			cnt++;
			gph[e[i].s].push_back(pi(e[i].y, e[i].e));
			gph[e[i].e].push_back(pi(e[i].y, e[i].s));
		}
		else{
			dep[e[i].s] = 0;
			dfs(e[i].s, -1);
			int pw = -1, wp = -1;
			for(int j=e[i].e; j!=e[i].s; j=par[j]){
				if(pw < pae[j]){
					pw = pae[j];
					wp = j;
				}
			}
			if(pw > e[i].y){
				rem_edge(par[wp], wp);
				gph[e[i].s].push_back(pi(e[i].y, e[i].e));
				gph[e[i].e].push_back(pi(e[i].y, e[i].s));
			}
		}
		if(cnt == n-1){
			int mx = 0;
			for(int j=1; j<=n; j++){
				for(auto &k : gph[j]){
					mx = max(mx, k.first);
				}
			}
			ret = min(ret, 1ll * p * e[i].x + 1ll * q * mx);
		}
	}
	if(ret > 4e18) ret = -1;
	cout << ret;
}