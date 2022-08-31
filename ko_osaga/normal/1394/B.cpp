#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using pi = pair<int, int>;
using lint = unsigned long long;
const int MAXN = 500005;

lint a[MAXN], tot;
lint val[10][10];
vector<pi> gph[MAXN];
int n, m, k, dap;

void dfs(int x, lint sum = 0){
	if(x == k + 1){
		if(sum == tot) dap++;
		return;
	}
	for(int i=1; i<=x; i++){
		dfs(x + 1, sum + val[x][i]);
	}
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++){
    	a[i] = uniform_int_distribution<int>(0, (1 << 31) - 1)(rng);
    	a[i] = a[i] << 31;
    	a[i] += uniform_int_distribution<int>(0, (1 << 31) - 1)(rng);
    	tot += a[i];
	}
	for(int i=0; i<m; i++){
		int u, v, w; scanf("%d %d %d",&u,&v,&w);
		gph[u].emplace_back(w, v);
	}
	for(int i=1; i<=n; i++){
		sort(all(gph[i]));
		for(int j=0; j<sz(gph[i]); j++){
			val[sz(gph[i])][j + 1] += a[gph[i][j].second];
		}
	}
	dfs(1);
	cout << dap << endl;
}