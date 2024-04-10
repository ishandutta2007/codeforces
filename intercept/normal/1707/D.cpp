#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=2009;
int n,mod;
int dp[M][M],p[M];
vector<int>g[M];
int c[M][M],s[M][M][2];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
void dfs(int u,int fa){
	if(g[u].size()==1&&fa){
		for(int i=1;i<n;++i){
			dp[u][i]=i;
		}
		return;
	}
	vector<int>p(n+1);
	for(int i=1;i<n;++i)p[i]=1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			for(int i=1;i<n;++i){
				p[i]=1ll*p[i]*dp[v][i]%mod;
			}
		}
	}
	for(int k=1;k<n;++k){
		s[k][0][0]=s[k][g[u].size()+1][1]=1;
		for(int i=1;i<=g[u].size();++i){
			int v=g[u][i-1];
			if(g[u][i-1]==fa){
				s[k][i][0]=s[k][i-1][0];
			}
			else{
				s[k][i][0]=1ll*s[k][i-1][0]*dp[v][k]%mod;
			}
		}
		for(int i=g[u].size();i>=1;--i){
			int v=g[u][i-1];
			if(g[u][i-1]==fa){
				s[k][i][1]=s[k][i+1][0];
			}
			else{
				s[k][i][1]=1ll*s[k][i+1][1]*dp[v][k]%mod;
			}
		}
	}
	if(fa){
		int k=g[u].size()-2;
		for(int i=1;i<n;++i){
			dp[u][i]=(dp[u][i-1]+mod-1ll*k*p[i]%mod)%mod;
		}
		int j=1;
		for(auto v:g[u]){
			if(v!=fa){
				int rex=0;
				for(int i=1;i<n;++i){
					rex=(rex+1ll*s[i][j-1][0]*s[i][j+1][1]%mod)%mod;
					dp[u][i]=(dp[u][i]+1ll*rex*dp[v][i]%mod)%mod;
				}
			}
			j++;
		}
	}
	else{
		for(int i=1;i<n;++i){
			for(int j=1;j<i;++j)p[i]=(p[i]+mod-1ll*p[j]*c[i][j]%mod)%mod;
		}
		for(int i=1;i<n;++i)cout<<p[i]<<" ";
		puts("");
	}
}
int main(){
	cin>>n>>mod;
	for(int i=0;i<=n;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	return 0;
}
/*
4 998244353
1 2
2 3
2 4
*/