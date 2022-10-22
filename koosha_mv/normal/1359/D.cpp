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

const int N=5e5+99,e=-31;

int t,n,ans,a[N],dp[N];

int solve(int x){
	int ans=0;
	f(i,1,n+1){
		dp[i]=0;
		if(a[i]<=x){ maxm(dp[i],dp[i-1]+a[i]); }
		else dp[i]=max(dp[i-1],0);
		maxm(ans,dp[i]);
	}
	ans-=x;
	return ans;
}

int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f_(i,30,0){
		maxm(ans,solve(i));
	}
	cout<<ans;
}