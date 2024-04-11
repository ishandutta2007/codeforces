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
#define int ll

const int N=2e5+100,inf=1e9+2;

int n,m,t,x,y,ans,p[N],h[N];
ll G[N],b[N];
vector<int> g[N];

void dfs(int x,int par){
	b[x]+=p[x];
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			G[x]+=G[g[x][i]];
			b[x]+=b[g[x][i]];
		}
	int sum=G[x]+b[x];
	if((sum+inf)%2!=(h[x]+inf)%2 || G[x]-b[x]>h[x] || sum<h[x]) ans=0;
	G[x]=h[x]+(sum-h[x])/2;
	b[x]=(sum-h[x])/2;
}

main(){
	cin>>t;
	while(t--){
		ans=1;
		f(i,1,n+1) g[i].clear(),G[i]=b[i]=0;
		cin>>n>>m;
		f(i,1,n+1) get(p[i]);
		f(i,1,n+1) get(h[i]);
		f(i,1,n){
			Get(x,y);
			g[x].pb(y);
			g[y].pb(x);
		}
		dfs(1,0);
		cout<<(ans ? "YES" : "NO" )<<'\n';
	}
}