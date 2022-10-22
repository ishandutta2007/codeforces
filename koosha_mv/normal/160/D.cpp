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

const int N=1e6+99;

int n,t,m,a[N],dp[N],vis[N],par[N],mark[N],edge[N][2];
map<int,int> ans[N];
vector<pair<int,int> > v[N];
vector<pair<int,pair<int,int> > > g[N];

int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void dfs(int x,int par){
	vis[x]=1;
	f(i,0,g[x].size()){
		if(vis[g[x][i].F]){
			dp[x]++;
			dp[g[x][i].F]--;
		}
	}
	f(i,0,g[x].size()){
		if(!vis[g[x][i].F]){
			dfs(g[x][i].F,x);
			dp[x]+=dp[g[x][i].F];
		}
	}
	f(i,0,g[x].size()){
		if(g[x][i].F==par){
			if(dp[x]==1){
				ans[g[x][i].S.F][g[x][i].S.S]=2;
			}
		}
	}
}
int main(){
	fill(par,par+N,-1);
	cin>>n>>m;	
	f(i,0,m){
		int x,y,w;
		cin>>x>>y>>w;
		edge[i][0]=x,edge[i][1]=y;
		v[w].pb(mp(x,y));
	}
	f(w,0,N){
		vector<int> vtx;
		f(i,0,v[w].size()){
			int x=v[w][i].F,y=v[w][i].S,u=Get_par(x),v=Get_par(y);
			if(u==v) continue;
			ans[x][y]=1;
			if(!mark[u]){
				vtx.pb(u);
				mark[u]=1;
			}
			if(!mark[v]){
				vtx.pb(v);
				mark[v]=1;
			}
			g[u].pb(mp(v,mp(x,y)));
			g[v].pb(mp(u,mp(x,y)));
		}
		f(i,0,vtx.size()){
			if(!vis[vtx[i]]){
				dfs(vtx[i],0);
			}
		}
		f(i,0,v[w].size()){
			merge(v[w][i].F,v[w][i].S);
		}
		f(i,0,vtx.size()){
			g[vtx[i]].clear();
			mark[vtx[i]]=vis[vtx[i]]=dp[vtx[i]]=0;
		}
	}
	f(i,0,m){
		if(ans[edge[i][0]][edge[i][1]]==0){
			cout<<"none"<<'\n';	
		}
		if(ans[edge[i][0]][edge[i][1]]==1){
			cout<<"at least one"<<'\n';
		}
		if(ans[edge[i][0]][edge[i][1]]==2){
			cout<<"any"<<'\n';
		}
	}
}