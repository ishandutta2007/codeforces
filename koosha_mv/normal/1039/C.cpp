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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=5e5+99,mod=1e9+7;

int n,m,l,r,x,y,cmp,par[N];
ll k,ans,c,p,a[N],t[N];
pair<int,pair<int,int> > edge[N];

void make(){
	t[0]=1;
	f(i,1,N) t[i]=t[i-1]*2ll%mod;
	f(i,1,N) par[i]=-1;
}
int Get_par(int u){
	if(par[u]<0) return u;
	return (par[u]=Get_par(par[u]));
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(u==v) return ;
	if(u>v) swap(u,v);
	par[u]+=par[v];
	par[v]=u,cmp--;
}

main(){
	make();
	cin>>n>>m>>k;
	c=(1ll<<k)%mod;
	f(i,1,n+1) get(a[i]);
	f(i,0,m){
		Get(x,y);
		edge[i].S.F=x,edge[i].S.S=y;
		edge[i].F=a[x]^a[y];
	}
	sort(edge,edge+m);
	while(l!=m){
		c--;
		while(edge[r].F==edge[l].F)
			r++;
		cmp=n;
		f(i,l,r)
			merge(edge[i].S.F,edge[i].S.S);
		ans=(ans+t[cmp])%mod;
		f(i,l,r) par[edge[i].S.F]=par[edge[i].S.S]=-1;
		l=r;
	}
	ans=(ans+1ll*c*t[n]%mod)%mod;
	cout<<ans;
}