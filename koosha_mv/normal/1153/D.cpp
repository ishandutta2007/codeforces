#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+9;
ll x,y,n,dp[N],brg[N],a[N];
vector<int> g[N];
void barg(int x){
	brg[x]=(g[x].size()==0);
	f(i,0,g[x].size()){
		barg(g[x][i]);
		brg[x]+=brg[g[x][i]];
	}
}
void dfs(int x){
	dp[x]=1;
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		if(a[x]==1)
			dp[x]=max(dp[x],brg[x]-(brg[g[x][i]]-dp[g[x][i]]));
		else
			dp[x]+=(dp[g[x][i]]-1);
	}
}
int main(){
	cin>>n;
	f(i,1,n+1) scanf("%I64d",&a[i]);
	f(i,2,n+1){
		scanf("%I64d",&x);
		g[x].pb(i);
	}
	barg(1);
	dfs(1);
	cout<<dp[1];
}