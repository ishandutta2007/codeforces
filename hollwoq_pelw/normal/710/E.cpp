#include<bits/stdc++.h>
using namespace std;
long long n,x,y,i,dp[10000007];
int main(){cin>>n>>x>>y;for(i=1;i<=n;i++)dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+y+(i&1)*x);cout<<dp[n];}