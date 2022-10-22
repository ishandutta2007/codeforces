#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
// 0: tedad 1:tool p rt 2:vazn

const int N=1e5+9;
ll n,x,y,l,r,mid,p,S,L,w[N],dp[N][3],masir[N];
vector<ll> g[N];
ll binary_search(ll t,ll v,ll x){
	l=max(1ll*-1,x-t-1),r=x;
	while(l+1<r){
		mid=(l+r)/2;
		if(masir[x-1]-masir[mid-1]<=v) r=mid;
		else l=mid;
	}
	return r;
}
void dfs(ll x,ll dist){
	if(!g[x].size()){
		dp[x][0]=1,dp[x][1]=1,dp[x][2]=w[x];
		return ;
	}
	
	ll mn=3e5,an=-1;
	masir[dist]=w[x];
	if(dist) masir[dist]+=masir[dist-1];
	f(i,0,g[x].size()){
		dfs(g[x][i],dist+1);
		dp[x][0]+=dp[g[x][i]][0];
		p=binary_search(L-dp[g[x][i]][1],S-dp[g[x][i]][2],dist+1);
		if(p<mn)
			mn=p,an=g[x][i];
	}
	if(mn==dist+1) dp[x][0]++,dp[x][1]=1,dp[x][2]=w[x];
	else 
		dp[x][1]=dp[an][1]+1,dp[x][2]=dp[an][2]+w[x];
}
int main(){
	cin>>n>>L>>S;
	f(i,1,n+1){
		get(w[i]);
		if(w[i]>S)
			return cout<<-1,0;
	}
	f(i,2,n+1){
		get(x);
		g[x].pb(i);
	}
	dfs(1,0);
	cout<<dp[1][0];
}