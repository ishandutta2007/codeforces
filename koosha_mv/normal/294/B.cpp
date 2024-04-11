#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int dp[205],n,x,y,sum;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>x>>y;sum+=y;
		f_(j,204,x+1) if(dp[j-x]>0) dp[j]=max(dp[j],dp[j-x]+y);
		dp[x]=max(dp[x],y);}
	f(i,0,203) if(sum-dp[i]<=i){cout<<i;return 0;}
}