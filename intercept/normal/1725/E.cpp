#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n;
int a[M],dp[M];
int num,vis[M],pri[M];
void pre(){
    for(int i=2;i<M;++i){
        if(!vis[i])vis[i]=i,pri[++num]=i;
        for(int j=1;j<=num&&1ll*pri[j]*i<M;++j){
            vis[i*pri[j]]=pri[j];
            if(i%pri[j]==0)break;
        }
    }
}
int p[M];
vector<int>g[M];
map<int,int>mp[M];
int calc(int x,int y){
	y-=x;
	return (1ll*x*(x-1)/2%mod*y%mod+1ll*y*(y-1)/2%mod*x%mod)%mod;
}
int ans=0;
void dfs(int u,int fa){
	for(auto o:mp[u]){
		dp[u]=(dp[u]+calc(o.se,p[o.fi]))%mod;
	}
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			if(mp[u].size()<mp[v].size())swap(mp[u],mp[v]),dp[u]=dp[v];
			for(auto o:mp[v]){
				dp[u]=(dp[u]+mod-calc(mp[u][o.fi],p[o.fi]))%mod;
				mp[u][o.fi]+=o.se;
				dp[u]=(dp[u]+calc(mp[u][o.fi],p[o.fi]))%mod;
			}
		}
	}
	if(u>1)ans=(ans+dp[u])%mod;
}
int main(){
	pre();
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		while(x>1){
			int y=vis[x];
			p[y]++;
			mp[i][y]=1;
			while(x%y==0)x/=y;
		}
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}