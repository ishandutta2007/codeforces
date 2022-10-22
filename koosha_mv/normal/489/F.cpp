#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=505;
ll n,m,mod,dp[N][N],k,t1,t2;
string s[N];
ll e(ll x){
	return x*(x-1)/2;
}
ll dfs(ll x,ll y){
	if(dp[x][y]>=0)
		return dp[x][y];
	if(((y+(n-x-y)*2)/2)<=m) return 0;
	dp[x][y]=(dfs(x,y+2)*e(y+2))%mod;;
	if(y>1)
		dp[x][y]=(dp[x][y]+dfs(x+2,y-2)*e(x+2))%mod;
	dp[x][y]=(dp[x][y]+dfs(x+1,y)*(x+1)*y)%mod;
	return dp[x][y];
}
int main(){
	cin>>n>>m>>mod;
	f(i,0,N) f(j,0,N) dp[i][j]=-1;
	f(i,0,m)
		cin>>s[i];
	f(i,0,n){
		k=0;
		f(j,0,m)
			k+=(s[j][i]=='1');
		if(k>2) return cout<<0,0;
		t1+=(k==0);
		t2+=(k==1);
	}
	dp[t1][t2]=1;
	cout<<dfs(0,0);
}