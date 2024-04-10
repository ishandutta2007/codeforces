#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
int n;
vector<pii>g[M];
ll f[M][5],dp[M],pd[M];
void merge(int u,int v,int w){
	for(int i=0;i<4;++i){
		if(f[u][i]<f[v][0]+w){
			for(int j=3;j>i;--j){
				f[u][j]=f[u][j-1];
			}
			f[u][i]=f[v][0]+w;
			break;
		}
	}
}
void dfs(int u,int fa){
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(v!=fa){
			dfs(v,u);
			merge(u,v,w);
			dp[u]=max(dp[u],dp[v]);
		}
	}
	dp[u]=max(dp[u],f[u][0]+f[u][1]);

}
ll sum=0,ans=0;
void pfs(int u,int fa){
	ans=max(ans,f[u][0]+f[u][1]+f[u][2]+f[u][3]);
	ll ff=0,ss=0;
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(v!=fa){
			if(ff<dp[v])ss=ff,ff=dp[v];
			else if(ss<dp[v])ss=dp[v];
			if(f[v][0]+w==f[u][1])f[v][4]=f[u][0]+w,pd[v]=f[u][0]+f[u][4];
			else f[v][4]=f[u][1]+w,pd[v]=f[u][1]+f[u][4];
			f[v][4]=max(f[v][4],f[u][4]+w);
			if(f[v][0]+w<=f[u][2]){
				pd[v]=max(pd[v],f[u][0]+f[u][1]);
			}
			else if(f[v][0]+w==f[u][1]){
				pd[v]=max(pd[v],f[u][0]+f[u][2]);
			}
			else pd[v]=max(pd[v],f[u][1]+f[u][2]);
			pd[v]=max(pd[v],pd[u]);
			ans=max(ans,f[v][0]+f[v][1]+f[v][2]+f[v][4]);
		}	
	}
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(v!=fa){
			pd[v]=max(pd[v],dp[v]==ff?ss:ff);
			ans=max(ans,dp[v]+pd[v]+w*2);
			pfs(v,u);
		}	
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].eb(v,w);
		g[v].eb(u,w);
		sum+=w*2;
	}
	dfs(1,0);
	pfs(1,0);
	cout<<sum-ans<<"\n";
	return 0;
}
/*
2
1 2 3
*/