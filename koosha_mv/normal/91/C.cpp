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

const int N=1e5+99,mod=1e9+9;

int n,t,m,u,v,ans=1,par[N];

int Get_Par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_Par(par[u]);
}
void merge(int u,int v){
	if((u=Get_Par(u))==(v=Get_Par(v))){ ans=ans*2ll%mod; return ; }
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}

int main(){
	fill(par,par+N,-1);
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		merge(u,v);
		cout<<ans-1<<'\n';
	}
}