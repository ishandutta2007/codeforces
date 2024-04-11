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

const int N=2e5+99;

int n,u,v,t[2],deg[N];
vector<int> g[N];

void dfs(int x,int par=0,bool dist=0){
	t[dist]++;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,!dist);
}

int main(){
	cin>>n;
	f(i,1,n){
		Gett(u,v);
		g[u].pb(v),g[v].pb(u);
	}
	dfs(1);
	cout<<min(t[0],t[1])-1;
}