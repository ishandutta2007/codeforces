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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,sq=320;
 
int n,m,x,y,cnt[N],col[N],a[N],ans[N];
int tdd[N][sq+5];
map<int,int> mark1[N],mark2[N];
vector<int> g[N];
vector<pair<int,int> > query[N];
 
void add1(int an,int x,int t){
	tdd[an][mark1[an][x]]--;
	mark1[an][x]+=t;
	tdd[an][mark1[an][x]]++;	
}
void add2(int an,int x,int t){
    mark2[an][x]+=t;
}
void dfs1(int x,int par){
	int mx=0,c=x;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs1(g[x][i],x);
			if(mark1[a[g[x][i]]].size()>mx)
				c=g[x][i],mx=mark1[a[g[x][i]]].size();
		}
	a[x]=a[c];
	if(c==x) a[x]=c;
	if(cnt[col[x]]<sq) add1(a[x],col[x],1);
	f(i,0,g[x].size())
		if(g[x][i]!=par && g[x][i]!=c){
			for(auto it:mark1[a[g[x][i]]])
			    add1(a[x],it.F,it.S);
			mark1[a[g[x][i]]].clear();
		}
	f(i,0,query[x].size())
	   f(j,query[x][i].F,sq)
	      ans[query[x][i].S]+=tdd[a[x]][j];
}
void dfs2(int x,int par){
   int mx=0,c=x;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs2(g[x][i],x);
			if(mark2[g[x][i]].size()>mx)
				c=g[x][i],mx=mark2[g[x][i]].size();
		}
	a[x]=c;
	if(cnt[col[x]]>=sq) add2(a[x],col[x],1);
	f(i,0,g[x].size())
		if(g[x][i]!=par && g[x][i]!=a[x]){
			for(auto it:mark2[a[g[x][i]]])
			    add2(a[x],it.F,it.S);
			mark2[a[g[x][i]]].clear();
		}
   f(i,0,query[x].size())
      for(auto it:mark2[a[x]])
      	if(it.S>=query[x][i].F)
            ans[query[x][i].S]++;
}
 
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		gett(col[i]);
		cnt[col[i]]++;
	}
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	f(i,0,m){
		Gett(x,y);
		query[x].pb(mp(y,i));
	}
	dfs1(1,0);
	dfs2(1,0);
	print(ans,m);
}