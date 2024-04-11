#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
int n,d,gem[30009],x,dp[50009][700],e=350,mx;
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>d;
	f(i,0,n){cin>>x;gem[x]++;}
	dp[d][350]=0+gem[d];
	f(i,d+1,30009){
		f(j,100,600){
			if(i-(d+(j-e))>=0 && (dp[i-(d+(j-e))][j]>=0 || dp[i-(d+(j-e))][j-1]>=0 || dp[i-(d+(j-e))][j+1]>=0)){
				dp[i][j]=max(max(dp[i-(d+(j-e))][j-1],dp[i-(d+(j-e))][j+1]),dp[i-(d+(j-e))][j]);
			}
			if(dp[i][j]>=0){
				dp[i][j]+=gem[i];
				mx=max(mx,dp[i][j]);
			}
		}
	}
	cout<<max(mx,gem[d]);
}