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

const int N=5e5+99;

int n,m,t,x,y,rt,mx,col[N],mark[N];
vector<int> g[N],v[N];

void dfs(int x,int par){
	f(i,0,v[x].size())
		mark[col[v[x][i]]]=1;
	int p=1;
	f(i,0,v[x].size())
		if(col[v[x][i]]==0){
			while(mark[p]) p++;
			col[v[x][i]]=p;
			p++;
		}
	f(i,0,v[x].size())
		mark[col[v[x][i]]]=0;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x);
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		cin>>t;
		if(t>mx) mx=t,rt=i;
		f(j,0,t){
			gett(x);
			v[i].pb(x);
		}
	}
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(rt,0);
	cout<<max(mx,1)<<endl;
	f(i,1,m+1)
		cout<<max(col[i],1)<<" ";
}