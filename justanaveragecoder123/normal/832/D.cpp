#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<int>> adj(100001);
int par[100001];
int level[100001];
int dp[100001][20];
void dfs(int x) {
	for(auto j:adj[x]) {
		if(par[j]==-1) {
			par[j]=x;
			level[j]=level[x]+1;
			dfs(j);
		}
	}
}

void init() {
	for(int i=1;i<=n;++i) {
		dp[i][0]=par[i];
	}
	
	for(int j=1;j<20;++j) {
		for(int i=1;i<=n;++i) {
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
}

int lca(int p, int q) {
	if(level[p]>level[q]) swap(p,q);
	for(int i=19;i>=0;i--) {
		while(dp[q][i] && level[dp[q][i]]>=level[p]) {
			q=dp[q][i];
		}
	}
	
	if(p==q) return p;
	
	for(int i=0;i<=19;++i) {
		while(dp[p][i]!=dp[q][i]) {
			p=dp[p][i];
			q=dp[q][i];
		}
	}
	
	return dp[p][0];
}


int dst(int x, int y) {
	int l=lca(x,y);
	return level[x]+level[y]-2*level[l]+1;
}

int calc(int s, int f, int t) {
	return (dst(s,f)+dst(f,t)-dst(s,t)+1)/2;
}


int main() {
	memset(par, -1, sizeof par);
	cin>>n>>q;
	for(int i=2;i<=n;++i) {
		int p;
		cin>>p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	
	}
	
	par[0]=par[1]=0;
	dfs(1);
	init();
	
	
	for(int i=0;i<q;++i) {
		int a,b,c;
		cin>>a>>b>>c;
		cout<<max(calc(a,b,c), max(calc(b,a,c),calc(a,c,b)))<<"\n";
	}
	
	return 0;
}