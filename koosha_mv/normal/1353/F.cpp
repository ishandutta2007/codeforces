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

const ll N=102,inf=2e18;

ll n,m,t,a[N][N],b[N*N],dp[N][N];
ll ans;

ll calc(ll x,ll y,ll z){
	if(z>y || x>=inf) return inf;
	return x+y-z;
}
ll solve(ll x){
	dp[0][0]=calc(0,a[0][0],x);
	f(i,0,n)
		f(j,0,m){
			if(i+j>0) dp[i][j]=inf;
			if(i>0)
				minm(dp[i][j],calc(dp[i-1][j],a[i][j],x+i+j));
			if(j>0)
				minm(dp[i][j],calc(dp[i][j-1],a[i][j],x+i+j));
		}
	return dp[n-1][m-1];
}

int main(){
	cin>>t;
	while(t--){
		ans=inf;
		cin>>n>>m;
		f(i,0,n)
			f(j,0,m)
				cin>>a[i][j];
		f(i,0,n)
			f(j,0,m)
				minm(ans,solve(a[i][j]-i-j));
		cout<<ans<<endl;
	}
}