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

const int N=2020;

int o,n,m,u,v,c,p,sum=1,ans[N],sub[N],cmp[N],mark1[N],mark2[N];
vector<int> g[N],g1[N];

void dfs(int x,int par,int dist){
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,dist+1);
	maxm(ans[cmp[x]],dist);
}
void dfs1(int x,int par){
	mark1[x]++;
	f(i,0,g1[x].size())
		if(g1[x][i]!=par && mark1[g1[x][i]])
			sub[x]++,sub[g1[x][i]]--;
	f(i,0,g1[x].size())
		if(!mark1[g1[x][i]])
			dfs1(g1[x][i],x),sub[x]+=sub[g1[x][i]];
	if(sub[x]==0)
		mark1[x]=2;
}
void dfs2(int x,int co,int comp){
	mark2[x]=1,cmp[co]=comp;
	f(i,0,g1[x].size())
		if(!mark2[g1[x][i]]){
			if(mark1[g1[x][i]]==2)
				g[co].pb(++c),g[c].pb(co),dfs2(g1[x][i],c,comp);
			else
				dfs2(g1[x][i],co,comp);
		}
}
void make_tree(){
	f(i,1,n+1)
		if(!mark1[i])
			dfs1(i,0);
	f(i,1,n+1)
		if(!mark2[i])
			dfs2(i,++c,++p);
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		g1[u].pb(v);
		g1[v].pb(u);
	}
	make_tree();
	
	f(rt,1,c+1) dfs(rt,0,0);
	f(i,1,c+1) ans[cmp[i]]+=(g[i].size()==1);
	f(i,1,N) if(ans[i]>0) sum+=ans[i]-2;
	cout<<n-sum;
}