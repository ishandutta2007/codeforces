#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=300009;
const int B=459;
int n,q;
int inv[M];
int f[M][23],dep[M],siz[M];
vector<int>g[M],so;
void dfs(int u,int fa){
	f[u][0]=fa;
	siz[u]=1;
	dep[u]=dep[fa]+1;
	so.eb(u);
	for(int i=1;i<20;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u),siz[u]+=siz[v];
	}
}
inline int lca(int x,int y){
	int d=dep[x]-dep[y]-1;
	if(d<0)return 0;
	for(int i=17;i>=0;--i){
		if(d>>i&1)x=f[x][i];
	}
	return x;
}
int o[M],x[M],y[M];
int val[M],a[M];
void add(int& x,int y){
	x+=y;
	x>=mod?x-=mod:0;
}
void build(int l){
	for(int i=1;i<=n;++i)a[i]=val[i]=0;
	for(int i=1;i<=l;++i){
		if(o[i]==1){
			add(val[x[i]],y[i]);
		}
	}
	for(int u=1;u<=n;++u){
		int p=1ll*val[u]*siz[u]%mod*inv[n]%mod;
		add(a[1],p);
		add(a[u],mod-p);
		for(auto v:g[u]){
			if(v!=f[u][0]){
				add(a[v],1ll*val[u]*(n-siz[v])%mod*inv[n]%mod);
			}
		}
	}
	for(auto u:so){
		int fa=f[u][0];
		add(a[u],a[fa]);
		add(val[u],a[u]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	for(int i=1,la=1;i<=q;++i){
		cin>>o[i]>>x[i];
		if(o[i]==1)cin>>y[i];
		if(o[i]==2){
			int ans=val[x[i]];
			for(int j=la;j<=i;++j){
				if(o[j]==1){
					int u=x[j],d=y[j],w=lca(x[i],u);
					if(u==x[i]){
						add(ans,d);
					}
					else if(f[w][0]==u){
						add(ans,1ll*d*(n-siz[w])%mod*inv[n]%mod);
					}
					else{
						add(ans,1ll*d*siz[u]%mod*inv[n]%mod);
					}
				}
			}
			cout<<ans<<"\n";
		}
		if(i%B==0)build(i),la=i+1;
	}
	return 0;
}