#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+99;
ll n,m,x,y,mark[N],par[N],cnt,pr[N],mark1[N],e=1e9;
vector<ll> g[N],g1[N],ans[N];
map<ll,ll> edge;
void dfs(int x){
	mark[x]=1;
	f(i,0,g1[x].size()){
		if(mark[g1[x][i]]==0){
			par[g1[x][i]]=x;
			dfs(g1[x][i]);
		}
		if(g1[x][i]!=par[x])
			g[x].pb(g1[x][i]);
	}
}
void dfs1(int x){
	mark1[x]=1;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]==0)
			dfs1(g[x][i]);
	}
	f(i,0,g[x].size()){
		if(edge[e*x+g[x][i]]==0){
			edge[e*x+g[x][i]]=1,edge[x+e*g[x][i]]=1;
			ans[x].pb(g[x][i]);
		}
	}
	if(ans[x].size()%2==1){
		edge[x*e+par[x]]=1,edge[par[x]*e+x]=1;
		ans[x].pb(par[x]);
	}
}	
int main(){
	cin>>n>>m;
	if(m%2==1){cout<< "No solution";return 0;}
	f(i,0,m){
		Get(x,y);
		g1[x].pb(y);
		g1[y].pb(x);
	}
	dfs(1);
	dfs1(1);
	f(j,1,n+1){
		for(int i=0;i<ans[j].size();i+=2){
			cout<<ans[j][i]<<" "<<j<<" "<<ans[j][i+1]<<endl;
		}
	}
}