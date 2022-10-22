#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=5e3+9;
ll n,dp[N][N],a[N],ans,i=1,p=1e9;
int main(){
	cin>>n;
	while(i<=n){
		cin>>a[i];
		if(a[i]<N)
			i++;
		else
			ans++,n--;
	}
	f(i,0,N){f(j,0,N) dp[i][j]=1e9;}
	dp[0][0]=0;
	f(i,1,n+1){
		f(j,0,a[i]+1)
			dp[i][j]=dp[i-1][min(j,a[i-1])]+(j-min(j,a[i-1])+(j<a[i]));
		f(j,a[i],N)
			minm(dp[i][a[i]],dp[i-1][j])
	}
	f(i,0,a[n]+1)
		minm(p,dp[n][i]);
	cout<<p+ans;
}