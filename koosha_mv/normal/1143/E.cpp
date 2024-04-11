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
const int N=1e6+9,k=19;
int n,m,q,l,r,a[N],p[N],par[N],gh[N],seg[N],mark[N],masir[N],ans[N],t[N],p1,c;
vector<int> g[N];
vector<pair<int,int> > query[N];
int Get_min(int x){
	int mn=1e6;
	p1=(1<<k);
	x=(1<<k)-x;
	f_(i,k-1,0){
		if(x>=(1<<i)){
			x-=(1<<i);
			p1-=(1<<i);
			minm(mn,t[p1]);
		}
	}
	return mn;
}
int solve_queries(){
	f(i,0,m){
		p1=0;
		c=i+1;
		seg[i]++;
		f_(j,k-1,0){
			if(c>=(1<<j)){
				c-=(1<<j);
				p1+=(1<<j);
				minm(t[p1],seg[i]);
			}
		}
		f(j,0,query[i].size())
			if(Get_min(query[i][j].F)<=i+1) ans[query[i][j].S]=1;
	}
}
void dfs(int x,int dist){
	mark[x]=1;
	masir[dist]=x;
	if(dist>=n-1) seg[x]=masir[dist-n+1];
	f(i,0,g[x].size())
		dfs(g[x][i],dist+1);
}
int main(){
	cin>>n>>m>>q;
	f(i,0,n)
		gett(p[i]);
	f(i,0,n) par[p[i]]=p[(i+1)%n];
	f(i,0,m) gett(a[i]);
	f_(i,m-1,0){
		if(gh[par[a[i]]]!=0 && a[i]<=n)
			g[gh[par[a[i]]]].pb(i);
		gh[a[i]]=i;
	}
	fill(seg,seg+m,1e6);
	f_(i,m-1,0)
		if(!mark[i])
			dfs(i,0);
	f(i,0,q){
		Gett(l,r);
		query[r-1].pb(mp(l,i));
	}
	fill(t,t+N,1e6);
	solve_queries();
	f(i,0,q) cout<<ans[i];
}