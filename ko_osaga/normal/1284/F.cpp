#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 250005;

vector<pi> gph[2][MAXN], v[2];
int n, par[2][MAXN], pae[2][MAXN], dep[2][MAXN];
int din[2][MAXN], dout[2][MAXN], piv;
int spt[18][MAXN];

int lca(int x, int y){
	if(dep[0][x] > dep[0][y]) swap(x, y);
	int dx = dep[0][y] - dep[0][x];
	for(int i=0; i<18; i++){
		if((dx >> i) & 1) y = spt[i][y];
	}
	for(int i=17; i>=0; i--){
		if(spt[i][x] != spt[i][y]){
			x = spt[i][x];
			y = spt[i][y];
		}
	}
	if(x != y) return spt[0][x];
	return x;
}

bool sub(int t, int x, int y){
	return din[t][x] <= din[t][y] && dout[t][y] <= dout[t][x];
}

void dfs(int t, int x, int p){
	din[t][x] = piv++;
	for(auto [e, i] : gph[t][x]){
		if(i == p) continue;
		par[t][i] = x;
		pae[t][i] = e;
		dep[t][i] = dep[t][x] + 1;
		dfs(t, i, x);
	}
	dout[t][x] = piv;
}

struct disj{
	vector<int> memb[MAXN];
	int grp[MAXN];
	void init(int n){
		for(int i=0; i<n; i++){
			memb[i].push_back(i);
			grp[i] = i;
		}
	}
	int find(int x){ return grp[x]; }
	void uni(int x, int y){
		x = find(x);
		y = find(y);
		if(sz(memb[x]) > sz(memb[y])) swap(x, y);
		for(auto &i : memb[x]){
			memb[y].push_back(i);
			grp[i] = y;
		}
		memb[x].clear();
	}
}disj;

int main(){
	scanf("%d",&n);
	for(int t=0; t<2; t++){
		for(int i=0; i<n-1; i++){
			int s, e; scanf("%d %d",&s,&e);
			s--, e--;
			gph[t][s].emplace_back(i, e);
			gph[t][e].emplace_back(i, s);
			v[t].emplace_back(s, e);
		}
		dfs(t, 0, -1);
		piv = 0;
	}
	for(int i=0; i<n; i++) spt[0][i] = par[0][i];
	for(int i=1; i<18; i++){
		for(int j=0; j<n; j++){
			spt[i][j] = spt[i-1][spt[i-1][j]];
		}
	}
	for(auto &[s, e] : v[1]){
		if(dep[1][s] > dep[1][e]) swap(s, e);
	}
	sort(all(v[1]), [&](const pi &a, const pi &b){
		return dep[1][a.second] > dep[1][b.second];
	});
	disj.init(n);
	printf("%d\n", n - 1);
	for(auto [s, e] : v[1]){
		int leaf_comp = disj.find(e);
		auto qr = [&](int x){
			return disj.find(x) == leaf_comp;
		};
		int l = lca(s, e);
		int ans = -1;
		if(qr(l)){
			ans = s;
			for(int i=17; i>=0; i--){
				if(dep[0][ans] - (1 << i) > dep[0][l] && !qr(spt[i][ans])){
					ans = spt[i][ans];
				}
			}
		}
		else{
			ans = e;
			for(int i=17; i>=0; i--){
				if(dep[0][ans] - (1 << i) > dep[0][l] && qr(spt[i][ans])){
					ans = spt[i][ans];
				}
			}
		}
		printf("%d %d %d %d\n", ans + 1, par[0][ans] + 1, s + 1, e + 1);
		if(!qr(ans)) disj.uni(ans, e);
		else disj.uni(par[0][ans], e);
	}
}