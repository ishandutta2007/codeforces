#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll dp[5002][5002],a[5002],x,n,m,k;
int main(){
	cin>>n>>m>>k;
	f(i,1,n+1){cin>>x;a[i]=a[i-1]+x;}
	f(i,m,n+1){
		f(j,1,k+1) dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+(a[i]-a[i-m]));
	}
	cout<<dp[n][k];
}