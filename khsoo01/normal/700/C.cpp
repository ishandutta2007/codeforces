#include<bits/stdc++.h>
using namespace std;
const int N = 1005, M = 30005, inf = 2.1e9;

int n, m, s, e, v[M], ans = inf;
int dfn[N], low[N], pv[N], pe[N], cc, tabu;
bool vis[N];

vector<pair<int,int> > adj[N];
vector<int> pth, op;

bool dfs (int I) {
	vis[I] = true;
	if(I == e) return true;
	for(auto &T : adj[I]) {
		int A, B; tie(A, B) = T;
		if(!vis[A]) {
			pth.push_back(B);
			if(dfs(A)) return true;
		}
	}
	if(!pth.empty()) pth.pop_back();
	return false;
}

void calc (int C, int P) {
	vis[C] = true;
	dfn[C] = low[C] = ++cc;
	for(auto &T : adj[C]) {
		int A, B; tie(A, B) = T;
		if(B == P || B == tabu) continue;
		if(vis[A]) {
			low[C] = min(low[C], dfn[A]);
		}
		else {
			pv[A] = C; pe[A] = B;
			calc(A, B);
			low[C] = min(low[C], low[A]);
		}
	}
}

void upd (int T, vector<int> V) {
	if(ans > T) {ans = T; op = V;}
}

void solve () {
	cc = 0;
	fill(vis, vis+n+1, 0);
	calc(s, 0);
	if(!vis[e]) {
		upd(v[tabu], {tabu});
		return;
	}
	for(int i=e;i!=s;i=pv[i]) {
		if(low[i] != dfn[i]) continue;
		upd(v[tabu] + v[pe[i]], {tabu, pe[i]});
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=1;i<=m;i++) {
		int A, B;
		scanf("%d%d%d",&A,&B,&v[i]);
		adj[A].push_back({B, i});
		adj[B].push_back({A, i});
	}
	if(!dfs(s)) {puts("0\n0"); return 0;}
	for(auto &T : pth) {
		tabu = T; solve();
	}
	if(ans == inf) {puts("-1"); return 0;}
	printf("%d\n%d\n",ans,op.size());
	for(auto &T : op) printf("%d ",T);
}