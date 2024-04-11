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
int n,k,x,y,ans[N],a,deg[N];
vector<pair<int,int> > g[N];
void dfs(int x,int c,int par){
	int col=(c+1)%a;
	f(i,0,g[x].size()){
		if(g[x][i].F!=par){
			ans[g[x][i].S]=col;
			dfs(g[x][i].F,col,x);
			col=(col+1)%a;
		}
	}
}
int main(){
	cin>>n>>k;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(mp(y,i));
		g[y].pb(mp(x,i));
		deg[x]++,deg[y]++;
	}
	sort(deg+1,deg+1+n);
	a=deg[n-k];
	cout<<a<<endl;
	dfs(1,-1,0);
	f(i,1,n)
		cout<<ans[i]+1<<" ";
}