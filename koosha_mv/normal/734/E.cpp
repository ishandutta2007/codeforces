#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=2e5+9;
int a[N],d1,ans,n,x,y;
vector<int> g[N];
void dfs(int x,int par,int dist){
	if(dist>ans) ans=dist,d1=x;
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs(g[x][i],x,dist+(a[x]!=a[g[x][i]]));
}
int main(){
	cin>>n;
	f(i,1,n+1)	cin>>a[i];
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0,0);
	dfs(d1,0,1);
	cout<<ans/2;	
}