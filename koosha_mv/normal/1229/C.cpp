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

int n,m,q,u,v,deg[N],degin[N];
ll ans;
vector<int> g[N];

void change(int u,int v){
	ans-=1ll*sz(g[u])*(deg[u]-sz(g[u]));
	g[u].pb(v);
	ans+=1ll*sz(g[u])*(deg[u]-sz(g[u]));
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		if(v<u) swap(u,v);
		g[u].pb(v);
		deg[u]++;
		deg[v]++;
	}
	f(i,1,n+1)
		ans+=1ll*sz(g[i])*(deg[i]-sz(g[i]));
	cout<<ans<<'\n';
	cin>>q;
	f(i,0,q){
		cin>>u;
		ans-=1ll*sz(g[u])*(deg[u]-sz(g[u]));
		f(i,0,sz(g[u]))
			change(g[u][i],u);
		g[u].clear();
		cout<<ans<<'\n';
	}
}