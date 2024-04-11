#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
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
 
int n,u,T,a[N],vis[N],cnt[N];
vector<pair<int,int> > ans,v[2],g[N];
map<pair<int,int>,int> mark;
 
void clear(){
	f(i,1,n+1) g[i].clear();
	fill(cnt,cnt+2+n,0);
	fill(vis,vis+2+n,0);
	mark.clear();
	ans.clear();
}
void dfs(int x,int rt,int dist){
	if(vis[x]) return ;
	vis[x]=1;
	f(i,0,g[x].size())
		if(!vis[g[x][i].F] || (g[x][i].F==rt && dist>1)){
			v[g[x][i].S].pb(mp(x,g[x][i].F));
			dfs(g[x][i].F,rt,dist+1);
			return ;
		}
}
void solve(){
	clear();
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	f(i,1,n+1){
		gett(u);
		cnt[u]++,cnt[a[i]]++;
		g[a[i]].pb(mp(u,1));
		g[u].pb(mp(a[i],0));
		mark[mp(a[i],u)]=mark[mp(u,a[i])]=i;
	}
	f(i,1,n+1) if(cnt[i]!=2){ cout<<-1<<endl; return; }
	
	f(i,1,n+1)
		if(!vis[i]){
			v[0].clear();
			v[1].clear();
			if(g[i][0].F==g[i][1].F){
				vis[i]=vis[g[i][0].F]=1;
				if(g[i][0].S==g[i][1].S)
					v[0].pb(mp(i,g[i][0].F)),v[1].pb(mp(i,g[i][0].F));
			}
			else
				dfs(i,i,0);
			if(v[0].size()<v[1].size())
				f(i,0,v[0].size())
					ans.pb(v[0][i]);
			else
				f(i,0,v[1].size())
					ans.pb(v[1][i]);
		}
	
	cout<<ans.size()<<'\n';
	f(i,0,ans.size())
		cout<<mark[ans[i]]<<" ";
	cout<<'\n';
}
 
int main(){
	cin>>T;
	while(T--) solve();
}