#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+9;
ll n,k,x,y,mark[N],mark1[N],masir[N],q1,mx1,center,mark2[N];
vector<ll> g[N];
void dfs(int x,int dis){
	mark[x]=1;
	if(dis>mx1) mx1=dis,q1=x;
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]) dfs(g[x][i],dis+1);
	}
}
void dfs1(int x,int dis){
	mark1[x]=1;
	masir[dis]=x;
	if(dis>mx1){
		mx1=dis;
		if(dis%2==0) center=masir[dis/2];
		else center=-1;
	}
	f(i,0,g[x].size()){
		if(!mark1[g[x][i]]) dfs1(g[x][i],dis+1);
	}
}
void check(int x,int dis){
	mark2[x]=1;
	if(x==center && g[x].size()<3){cout<<"NO";exit(0);}
	if(dis==mx1 && g[x].size()!=1){cout<<"NO";exit(0);}
	if(dis<mx1 && dis>0 && g[x].size()<4){cout<<"NO";exit(0);}
	f(i,0,g[x].size()){
		if(!mark2[g[x][i]]) check(g[x][i],dis+1);
	}
}
int main(){
	Get(n,k);
	f(i,1,n){
		Get(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	mx1=0;
	dfs1(q1,0);
	mx1/=2;
	if(center==-1 || mx1!=k){cout<<"NO";return 0;}
	check(center,0);
	cout<<"YES";
}