#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9;

int n,x,y,sz,sub[26][N],dist[26][N],ans[N];
vector<int> g[N],v;

void dfs(int x,int par,int col,int dis){
	sub[col][x]=1,dist[col][x]=dis;
	v.pb(x);
	f(i,0,g[x].size())
		if(g[x][i]!=par && ans[g[x][i]]==-1){
			dfs(g[x][i],x,col,dis+1);
			sub[col][x]+=sub[col][g[x][i]];
		}
}
void solve(int rt,int c){
	v.clear();
	dfs(rt,0,c,0);
	sz=v.size();
	int u,mx=-1;
	f(i,0,v.size())
		if(sub[c][v[i]]>=sz/2 && dist[c][v[i]]>mx)
			mx=dist[c][v[i]],u=v[i];
	ans[u]=c;
	f(i,0,g[u].size())
		if(ans[g[u][i]]==-1)	
			solve(g[u][i],c+1);
}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	fill(ans,ans+N,-1);
	solve(1,0);
	f(i,1,n+1) cout<<char('A'+ans[i])<<" ";
}