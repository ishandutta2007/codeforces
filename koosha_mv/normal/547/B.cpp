#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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

const int N=2e5+99;

int n,x,p,mx=1,ans[N],par[N],mark[N];
pair<int,int> a[N];

int Get_par(int u){
	if(par[u]<0) return u;
	return (par[u]=Get_par(par[u]));
}
void dsu(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	maxm(mx,par[u]*-1);
}
void solve(int x){
	if(x>0 && mark[x-1])
		dsu(x,x-1);
	if(x<n-1 && mark[x+1])
		dsu(x,x+1);
	mark[x]=1;
}

int main(){
	fill(par,par+N,-1);
	cin>>n;
	f(i,0,n){
		gett(a[i].F);
		a[i].S=i;
	}
	
	sort(a,a+n);
	f_(i,n-1,0){
		solve(a[i].S);
		ans[i]=mx;
	}
	p=n-1;
	f(i,1,n+1){
		while(p>0 && ans[p]<i) p--;
		cout<<a[p].F<<" ";
	}
}