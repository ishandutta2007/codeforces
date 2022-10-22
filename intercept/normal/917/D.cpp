#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
#define ma make_pair
using namespace std;
const int mod=1e9+7;
const int M=109;
int n;
int dp[M][M][M],siz[M],p[M][M],ans[M];
vector<int>g[M];
void add(int &x,int y){
	x+=y;
	x>=mod?x-=mod:0;
}
int kpow(int x,int y,int rex=1){
	if(y<0)return kpow(x,mod-2);
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
void dfs(int u,int fa){
	siz[u]=1;
	dp[u][0][1]=1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			for(int x=0;x<siz[u]+siz[v];++x){
				for(int y=0;y<=siz[u]+siz[v];++y){
					p[x][y]=0;
				}
			}
			for(int a=0;a<siz[u];++a){
				for(int b=0;b<siz[v];++b){
					for(int x=1;x<=siz[u];++x){
						for(int y=1;y<=siz[v];++y){
							add(p[a+b+1][x+y],1ll*dp[u][a][x]*dp[v][b][y]%mod);
							add(p[a+b][x],1ll*dp[u][a][x]*dp[v][b][y]%mod*y%mod);
						}
					}
				}
			}
			for(int x=0;x<siz[u]+siz[v];++x){
				for(int y=0;y<=siz[u]+siz[v];++y){
					dp[u][x][y]=p[x][y];
				}
			}
			siz[u]+=siz[v];
		}
	}
}
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int main(){
	pre();
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	for(int i=0;i<n;++i){
		for(int j=1;j<=n;++j){
			add(ans[i],1ll*dp[1][i][j]*j%mod*kpow(n,n-i-2)%mod);
		}
	}
	for(int i=n-1;i>=0;--i){
		for(int j=i+1;j<n;++j){
			ans[i]=(ans[i]+mod-1ll*c(j,i)*ans[j]%mod)%mod;
		}
	}
	for(int i=0;i<n;++i)cout<<ans[i]<<" \n"[i==n];
	return 0;
}
/*
2
1 2
*/