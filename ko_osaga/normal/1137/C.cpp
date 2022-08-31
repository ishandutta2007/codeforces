#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, m, d;
vector<int> gph[MAXN];
vector<int> rev[MAXN];
int vis[MAXN], comp[MAXN], piv;
char str[MAXN][55];
vector<int> dfn;

void dfs(int x){
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(!vis[i]) dfs(i);
	}
	dfn.push_back(x);
}

void rdfs(int x, int p){
	comp[x] = p;
	for(auto &i : rev[x]){
		if(!comp[i]) rdfs(i, p);
	}
}

void get_scc(int n){
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &i : dfn){
		if(!comp[i]) rdfs(i, ++piv);
	}
}

int gcd(int x, int y){ return y ? gcd(y, x%y) : x; }

vector<int> cmp[MAXN];
vector<pi> inedge[MAXN];
int dp[MAXN][55], dep[MAXN];
int gv;

void dfsx(int x){
	vis[x] = 1;
	for(auto &i : gph[x]){
		if(comp[x] != comp[i]) continue;
		if(vis[i]){
			int cur = dep[x] + 1;
			int nxt = dep[i];
			if(cur != nxt) gv = gcd(gv, abs(cur - nxt));
		}
		else{
			dep[i] = dep[x] + 1;
			dfsx(i);
		}
	}
}

void spread(int p){
	gv = d;
	dfsx(cmp[p][0]);
	int max_val[55] = {};
	fill(max_val, max_val + gv, -1e9);
	for(auto &i : cmp[p]){
		for(int j=0; j<d; j++){
			int val = dp[i][j];
			int idx = (j + gv - dep[i] % gv) % gv;
			max_val[idx] = max(max_val[idx], val);
		}
	}
	for(auto &i : cmp[p]){
		int good[55] = {};
		for(int j=0; j<d; j++){
			if(str[i][j] == '1'){
				int idx = (j + gv - dep[i] % gv) % gv;
				good[idx] = 1;
			}
		}
		for(int j=0; j<gv; j++){
			max_val[j] += good[j];
		}
	}
	for(auto &i : cmp[p]){
		for(int k=0; k<d; k++){
			int want_idx = (k - dep[i]) % gv + gv;
			want_idx %= gv;
			dp[i][k] = max(dp[i][k], max_val[want_idx]);
		}
	}
	for(auto &i : cmp[p]){
		for(auto &j : gph[i]){
			if(p != comp[j]){
				for(int k=0; k<d; k++){
					dp[j][(k+1)%d] = max(dp[j][(k+1)%d], dp[i][k]);
				}
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		rev[e].push_back(s);
	}
	for(int i=1; i<=n; i++) scanf("%s", str[i]);
	get_scc(n);
	for(int i=1; i<=n; i++) for(int j=0; j<d; j++) dp[i][j] = -1e9;
	dp[1][0] = 0;
	for(int i=1; i<=n; i++){
		cmp[comp[i]].push_back(i);
		for(auto &j : gph[i]){
			if(comp[j] == comp[i]) inedge[comp[i]].emplace_back(i, j);
		}
		vis[i] = 0;
	}
	for(int i=1; i<=piv; i++) spread(i);
	int ret = 0;
	for(int i=1; i<=n; i++) for(int j=0; j<d; j++) ret = max(ret, dp[i][j]);
	cout << ret << endl;
}