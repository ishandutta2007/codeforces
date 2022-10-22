#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2e5+9;
ll b[N],a[N],at[N],n,m,x,y,tvn=262144,k=19,ct,cnt,p,dist[N],ans,r;
string s;
vector<ll> g[N];
map<ll,ll> z;
string binary(ll m,ll k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
void dfs(int x,int par,int dis){
	a[x]=cnt++,dist[x]=dis;
	f(i,0,g[x].size()){
		if(g[x][i]!=par) dfs(g[x][i],x,dis+1);
	}
	at[x]=cnt-1;
}
void update(int x,int val){
	s=binary(a[x],k),p=0,ct=tvn;
	f_(i,k-1,0){
		if(s[i]=='1'){
			p+=ct;
			z[p]+=val;
		}
		ct/=2;
	}
	s=binary(at[x]+1,k),p=0,ct=tvn;
	f_(i,k-1,0){
		if(s[i]=='1'){
			p+=ct;
			z[p]-=val;
		}
		ct/=2;
	}
}
ll solve(ll d){
	p=tvn*2,ct=tvn;
	s=binary(tvn*2-1-d,k),r=0;
	f_(i,k-1,0){
		if(s[i]=='1'){
			p-=ct;
			r+=z[p];
		}
		ct/=2;
	}
	return r;
}
int main(){
	Get(n,m);
	f(i,0,n) get(b[i+1]);
	f(i,0,n-1){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0,0);
	f(i,0,m){
		get(x);
		if(x==1){
			Get(x,y);
			if(dist[x]%2==1) y=-y;
			update(x,y);
		}
		else{
			get(x);
			ans=solve(a[x]);
			if(dist[x]%2==0) ans=-ans;
			cout<<ans+b[x]<<endl;
		}
	}
}