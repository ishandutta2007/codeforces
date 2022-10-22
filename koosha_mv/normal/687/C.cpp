#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,k,dp[1009][1009],v,ans;
int main(){
	cin>>n>>k;dp[0][0]=1;
	f(l,0,n){
		cin>>v;
		f_(j,501,0){
			f_(k1,501,0){
				if(dp[j][k1]==1) dp[j][k1+v]=dp[j+v][k1]=1;
			}
		}
	}
	f(i,0,k+1){
		if(dp[i][k-i]==1) ans++;
	}
	cout<<ans<<endl;
	f(i,0,k+1){
		if(dp[i][k-i])cout<<i<<" ";
	}
}