#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=209;
int n;
int dp[M][M],f[M][11],dep[M];
vector<int>g[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
void dfs(int u,int fa){
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=10;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=10;i>=0;--i)if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	for(int i=10;i>=0;--i){
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	}
	return f[v][0];
}
int main(){
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dp[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(i==0&&j==0)continue;
			dp[i][j]=1ll*((i?dp[i-1][j]:0)+(j?dp[i][j-1]:0))%mod*kpow(2,mod-2)%mod;
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		dfs(i,0);
		for(int j=1;j<=n;++j){
			for(int k=1;k<j;++k){
				int w=lca(j,k),p=ans;
				if(w==j){
					ans=(ans+kpow(n,mod-2))%mod;
				}
				else if(w!=k){
					int l=dep[j]-dep[w];
					int r=dep[k]-dep[w];
					ans=(ans+1ll*kpow(n,mod-2)*dp[l-1][r-1]%mod*kpow(2,mod-2)%mod)%mod;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
1
1000000000 1000000000 
*/