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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

// dp1[x]=mxleaf , dp2[x]=ghotr subtree x , dp3[x]=masir amoodi + masir.
int n,u,v,a[N];
ll ans,b[N][3],R[N],dp1[N],dp2[N],dp3[N];
vector<int> g[N];
set<pair<ll,int> > s[N];
pair<ll,int> p;

ll calc_ans1(int u,int x){
	pair<ll,int> mx1=mp(0,0),mx2=mp(0,0);
	s[x].erase(mp(dp1[u],u));
	if(s[x].size()){
		mx1=*s[x].rbegin();
		s[x].erase(mx1);
	}
	if(s[x].size()){
		mx2=*s[x].rbegin();
		s[x].erase(mx2);
	}
	s[x].insert(mp(dp1[u],u));
	if(mx1.S)
		s[x].insert(mx1);
	if(mx2.S)
		s[x].insert(mx2);
	return dp2[u]+mx1.F+mx2.F;
}
ll calc_ans2(int u,int x){
	pair<ll,int> mx1=mp(0,0);
	s[x].erase(mp(dp1[u],u));
	if(s[x].size())
		mx1=*s[x].rbegin();
	s[x].insert(mp(dp1[u],u));
	return dp2[u]+mx1.F;
}
void dfs1(int x,int par){
	f(i,0,3) b[x][i]=0; 
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			b[x][0]=dp2[g[x][i]];
			sort(b[x],b[x]+3);
			maxm(dp1[x],dp1[g[x][i]]);
			s[x].insert(mp(dp1[g[x][i]],g[x][i]));
		}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			maxm(ans,calc_ans1(g[x][i],x)+a[x]);
	maxm(ans,b[x][1]+b[x][2]);
	if(s[x].size()){
		p=(*s[x].rbegin());
		s[x].erase(p);
		dp2[x]+=p.F;
	}
	if(s[x].size()){
		p=(*s[x].rbegin());
		s[x].erase(p);
		dp2[x]+=p.F;
	}
	dp1[x]+=a[x];
	dp2[x]+=a[x];
	maxm(dp2[x],b[x][2]);
}
void dfs2(int x,int par,int fa){
	ll mx=0;
	s[x].clear();
	f_(i,g[x].size()-1,0)
		if(g[x][i]!=par){
			R[g[x][i]]=mx;
			maxm(mx,dp1[g[x][i]]);
		}
	mx=fa;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs2(g[x][i],x,max(mx,R[g[x][i]])+a[x]);
			maxm(mx,dp1[g[x][i]]);
			s[x].insert(mp(dp1[g[x][i]],g[x][i]));
		}
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			maxm(ans,calc_ans2(g[x][i],x)+fa+a[x]);	
}

main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	cout<<ans<<'\n';
}