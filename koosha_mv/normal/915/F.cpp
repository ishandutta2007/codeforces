#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=1e6+9;
int n,x,y,a[N],par[N];
ll mn,mx;
pair<int,pair<int,int> >edge_mn[N],edge_mx[N];
vector<int> g[N];
int Get_par(int u){
	if(par[u]<0) return u;
	return (par[u]=Get_par(par[u]));
}
ll dsu(int u,int v){
	ll ans=1ll*par[Get_par(u)]*par[Get_par(v)];
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u; 
	return ans;
}
int main(){
	cin>>n;
	f(i,1,n+1) gett(a[i]);
	f(i,1,n){
		Gett(x,y);
		edge_mn[i]=mp(min(a[x],a[y]),mp(x,y));
		edge_mx[i]=mp(max(a[x],a[y]),mp(x,y));
	}
	sort(edge_mn+1,edge_mn+n);
	sort(edge_mx+1,edge_mx+n);
	fill(par,par+N,-1);
	f(i,1,n)
		mx+=dsu(edge_mx[i].S.F,edge_mx[i].S.S)*edge_mx[i].F;
	fill(par,par+N,-1);
	f_(i,n-1,1)
		mn+=dsu(edge_mn[i].S.F,edge_mn[i].S.S)*edge_mn[i].F;
	cout<<mx-mn<<endl;
}