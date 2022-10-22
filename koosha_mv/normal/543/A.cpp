#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long x,n,m,b,mod,dp[510][510],ans=0;
int main(){
	cin>>n>>m>>b>>mod;
	dp[0][0]=1;
	f(p,0,n){
		cin>>x;
		f(i,1,m+1){
			f(j,0,b+1){
				if(x<=j){
					dp[i][j]+=dp[i-1][j-x];
					dp[i][j]%=mod;
				}
				//cout<<dp[i][j]<<" ";
			}
			//cout<<endl;
		}
	}
	f(i,0,b+1){
		ans+=dp[m][i];
		ans%=mod;
	}
	cout<<ans;
}