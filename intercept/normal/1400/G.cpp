#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n,m;
int L[M],R[M],f[21],a[M],b[M],id[M],P[M];
int dp[M][21],d[M][21];
vector<int>g[M],p;
bool vis[M],in[M];
void dfs(int u){
	in[u]=1;
	p.eb(u);
	id[u]=p.size()-1;
	for(auto v:g[u]){
		if(!in[v])dfs(v);
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>L[i]>>R[i];
		dp[i][0]=1;
	}
	for(int i=1;i<=m;++i){
		cin>>a[i]>>b[i];
		vis[a[i]]=vis[b[i]]=1;
		g[a[i]].eb(b[i]);
		g[b[i]].eb(a[i]);
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		P[L[i]]++;
		P[R[i]+1]--;
	}
	for(int i=1;i<=n;++i)P[i]+=P[i-1];
	for(int i=1;i<=m;++i){
		if(!in[a[i]]){
			for(int k=1;k<=n;++k){
				for(int j=0;j<=m;++j)d[k][j]=0;
			}
			p.clear();
			dfs(a[i]);
			int t=p.size();
			for(int s=0;s<1<<t;++s){
				int l=1,r=n;
				bool bol=0;
				for(int j=0;j<t;++j){
					if(s>>j&1){
						l=max(l,L[p[j]]);
						r=min(r,R[p[j]]);
						for(auto v:g[p[j]]){
							if(s>>id[v]&1)bol=1;
						}
					}
				}
				if(bol||l>r)continue;
				int num=__builtin_popcount(s);
				d[l][num]++;
				d[r+1][num]--;
			}
			for(int k=1;k<=n;++k){
				for(int j=0;j<=m;++j)d[k][j]+=d[k-1][j],f[j]=0;
				for(int l=0;l<=m;++l){
					for(int r=0;r<=m;++r){
						if(l+r<=m){
							f[l+r]=(f[l+r]+1ll*dp[k][l]*d[k][r]%mod)%mod;
						}
					}
				}
				for(int j=0;j<=m;++j)dp[k][j]=f[j];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			ans=(ans+1ll*c(P[i],i-j)*dp[i][j]%mod)%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}