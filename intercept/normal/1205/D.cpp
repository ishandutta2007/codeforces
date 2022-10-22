#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=1009;
int n,m,maa=1e9,p=0;
int siz[M],f[M];
vector<int>g[M];
vector<pii>h[M];
int dp[M],pd[M];
void find(int u,int fa){
	f[u]=fa;
	siz[u]=1;
	int ma=0;
	for(auto v:g[u]){
		if(v!=fa){
			find(v,u);
			siz[u]+=siz[v];
			ma=max(ma,siz[v]);
		}
	}
	ma=max(ma,n-siz[u]);
	if(maa>ma){
		maa=ma;
		p=u;
	}
}
int num=0;
pii s[M];
bool vis[M];
int tot0=0,tot1=0,bo;
void dfs(int u,int fa,int o){
	for(auto v:g[u]){
		if(v!=fa){
			if(o)h[u].eb(v,++tot0);
			else h[u].eb(v,(++tot1)*bo);
			dfs(v,u,o);
		}
	}
}
void solve(int u,int dep){
	for(auto o:h[u]){
		int v=o.fi,w=o.se;
		cout<<u<<" "<<v<<" "<<w-dep<<"\n";
		solve(v,w);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	find(1,0);
	for(auto v:g[p]){
		if(v!=f[p]){
			s[++num]=make_pair(v,siz[v]);
		}
		else s[++num]=make_pair(v,n-siz[p]);
	}

	dp[0]=1;
	for(int i=1;i<=num;++i){
		for(int j=n;j>=s[i].se;--j){
			if(dp[j]==0&&dp[j-s[i].se]){
				dp[j]=1;
				pd[j]=i;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dp[i]&&i*(n-i)>=(n*n*2)/9){
			int u=i;
			bo=i;
			while(u){
				int x=pd[u];
				vis[s[x].fi]=1;
				u=u-s[x].se;
			}
			break;
		}
	}
	for(auto v:g[p]){
		if(vis[v])h[p].eb(v,++tot0);
		else h[p].eb(v,(++tot1)*bo);
		dfs(v,p,vis[v]);
	}
	solve(p,0);
	return 0;
}