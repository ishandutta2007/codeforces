#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,u,v,t,last,sub[N],par[N],deg[N];
queue<int> q;
vector<int> cent,g[N];
vector<pair<int,pair<int,int> > > ans;

void read(){
	cin>>n;
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
}
void dfs(int x,int par){
	bool is_cent=1;
	sub[x]=1;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			sub[x]+=sub[g[x][i]];
			is_cent&=(sub[g[x][i]]<=n/2);
		}
	is_cent&=(n-sub[x]<=n/2);
	if(is_cent)
		cent.pb(x);
}
void dfs1(int x,int rt){
	if(x!=rt && par[x]!=rt && g[x].size()==1) q.push(x);
	f(i,0,g[x].size())
		if(g[x][i]!=par[x]){
			par[g[x][i]]=x;
			dfs1(g[x][i],rt);
		}
}
void change(int u,int rt,int cent){
	ans.pb(mp(cent,mp(last,u)));
	ans.pb(mp(u,mp(par[u],rt)));
	deg[par[u]]--;
	last=u;
	if(par[par[u]]!=rt && deg[par[u]]==1)
		q.push(par[u]);
}
void solve(int rt,int cent){
	par[rt]=cent;
	dfs1(rt,rt);
	last=rt;
	while(q.size()){
		int u=q.front();
		q.pop();
		change(u,rt,cent);
	}
	ans.pb(mp(cent,mp(last,rt)));
}
void do_it(){
	f(k,0,sz(cent)){
		u=cent[k];
		f(i,0,g[u].size())
			if(g[u][i]!=cent[0] && g[u][i]!=lst(cent))
				solve(g[u][i],cent[k]);
	}
	cout<<sz(ans)<<'\n';
	f(i,0,sz(ans))
		cout<<ans[i].F<<" "<<ans[i].S.F<<" "<<ans[i].S.S<<'\n';
}
void find_centroids(){
	dfs(1,0);
}

int main(){
	read();
	find_centroids();
	do_it();
}