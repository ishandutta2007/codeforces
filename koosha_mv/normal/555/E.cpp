#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,lg=20;

int n,m,q,cnp,cnt,s[N],t[N],par[lg][N],dp0[N],dp1[N],vis[N],mark[N],cut_edge[N];
vector<int> g[N];

bool is_par(int u,int v){
	return s[u]<=s[v] && s[v]<=t[u];
}
int lca(int u,int v){
	if(is_par(u,v)) return u;
	f_(i,lg-1,0){
		if(!is_par(par[i][u],v)){
			u=par[i][u];
		}
	}
	return par[0][u];
}
void dfs1(int x,int col){
	int opo=0;
	vis[x]=1;
	s[x]=cnt++;
	mark[x]=col;
	f(i,1,lg)
		par[i][x]=par[i-1][par[i-1][x]];
	f(i,0,g[x].size()){
		if(vis[g[x][i]] && (g[x][i]!=par[0][x] || opo)){
			dp0[x]++;
			dp0[g[x][i]]--;
		}
		if(g[x][i]==par[0][x]){
			opo=1;
		}
	}
	f(i,0,g[x].size()){
		if(!vis[g[x][i]]){
			par[0][g[x][i]]=x;
			dfs1(g[x][i],col);
			dp0[x]+=dp0[g[x][i]];
		}
	}
	t[x]=cnt++;	
	if(dp0[x]==0) cut_edge[x]=1; 
}
void dfs2(int x){
	vis[x]=1;
	f(i,0,g[x].size()){
		if(!vis[g[x][i]]){
			dfs2(g[x][i]);
			dp0[x]+=dp0[g[x][i]];
			dp1[x]+=dp1[g[x][i]];
		}
	}
	if(dp0[x] && dp1[x] && cut_edge[x]){
		cout<<"No";
		exit(0);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1){
		if(!vis[i]){
			par[0][i]=i;
			dfs1(i,++cnp);
		}
	}

	fill(dp0,dp0+N,0);
	fill(vis,vis+N,0);
	f(i,0,q){
		int u,v,x;
		cin>>u>>v;
		if(mark[u]!=mark[v]) return cout<<"No",0;
		x=lca(u,v);
		dp0[u]++,dp0[x]--;
		dp1[v]++,dp1[x]--;
	}
	f(i,1,n+1){
		if(!vis[i]){
			dfs2(i);
		}
	}
	cout<<"Yes";
}