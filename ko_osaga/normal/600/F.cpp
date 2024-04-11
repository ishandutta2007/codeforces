#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 1005;
const int MAXM = 100005;

struct edge_color{
	int n, m;
	int deg[2][MAXN];
	pair<int,int> has[2][MAXN][MAXN];
	int color[MAXM];
	int c[2];

	void dfs(int x, int p) {
		auto i = has[p][x][c[!p]];
		if (has[!p][i.first][c[p]].second) dfs(i.first,!p);
		else has[!p][i.first][c[!p]] = pi(0,0);
		has[p][x][c[p]] = i;
		has[!p][i.first][c[p]] = pi(x,i.second);
		color[i.second] = c[p];
	}

	int solve(vector<pi> v, vector<int> &cv){
		m = sz(v);
		int ans = 0;
		for (int i=1;i<=m;i++) {
			int x[2];
			x[0] = v[i-1].first;
			x[1] = v[i-1].second;
			for (int d=0;d<2;d++) {
				deg[d][x[d]]+=1;
				ans = max(ans,deg[d][x[d]]);
				for (c[d]=1;has[d][x[d]][c[d]].second;c[d]++);
			}
			if (c[0]!=c[1]) dfs(x[1],1);
			for (int d=0;d<2;d++) has[d][x[d]][c[0]] = pi(x[!d],i);
			color[i] = c[0];
		}
		cv.resize(m);
		for(int i=1; i<=m; i++) cv[i-1] = color[i];
		return ans;
	}
}EC;

int main(){
	int m;
	scanf("%*d %*d %d",&m);
	vector<int> ret;
	vector<pi> v;
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		v.emplace_back(s, e);
	}
	printf("%d\n", EC.solve(v, ret));
	for(auto &i : ret) printf("%d ", i);
}