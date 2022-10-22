#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e4+99;
int ans,dp[2][N+100],e=5050,n,x,mod=1e9+7;
bool src;
int main(){
	cin>>n;
	f(j,0,n){
		src=j%2;
		cin>>x;
		f(i,0,N){
			if(i>x)
				dp[src][i]=dp[!src][i-x];
			if(N-i>x)
				dp[src][i]=(dp[src][i]+dp[!src][i+x])%mod;
		}
		dp[src][e+x]=(dp[src][e+x]+1)%mod;
		dp[src][e-x]=(dp[src][e-x]+1)%mod;
		ans+=dp[src][e];
		ans%=mod;
	}
	cout<<ans;
}