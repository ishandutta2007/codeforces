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

const int N=2e5+9;

int n,mark[N],ans[N];
pair<int,int> a[N];
vector<int> g[N];

void dfs(int x,int dist){
	mark[x]=1;
	ans[x]=dist%2+1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i],dist+1);
}

int main(){
	cin>>n;
	for(int i=1;i<2*n;i+=2)
		g[i].pb(i+1),g[i+1].pb(i);
	f(i,1,n+1){
		cin>>a[i].F>>a[i].S;
		g[a[i].F].pb(a[i].S);
		g[a[i].S].pb(a[i].F);
	}
	f(i,1,2*n)
		if(!mark[i])
			dfs(i,0);
	f(i,1,n+1)
		cout<<ans[a[i].F]<<" "<<ans[a[i].S]<<endl;
}