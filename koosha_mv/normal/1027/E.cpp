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
const int N=505,mod=998244353;
ll n,k,ans[N],dp[N][N];
ll sum;
int main(){
	cin>>n>>k;
	f(i,1,n+1){
		dp[i][0]=dp[i][1]=1;
		f(j,2,n+1){
			dp[i][j]=(dp[i][j-1]*2)%mod;
			if(j>i)
				dp[i][j]=(dp[i][j]+mod-dp[i][j-i-1])%mod;
		}
	}
	ans[1]=1;
	f(i,2,n+1)
		ans[i]=(dp[i][n]-dp[i-1][n]+mod)%mod;
	f(i,1,n+1)
		f(j,1,n+1)
			if(i*j<k)
				sum=(sum+(2ll*ans[i]*ans[j]))%mod;
	cout<<sum;
}