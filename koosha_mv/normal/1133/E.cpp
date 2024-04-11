#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll j,n,k,dp[5001][5001],a[5002];
int dpp(int x,int y){
	if(x<0 || y<0)
		return 0;
	return dp[x][y];
}
int main(){
	cin>>n>>k;

	f(i,1,n+1)	
		cin>>a[i];
	sort(a+1,a+n+1);
	f(i,1,n+1){
		f(l,1,k+1){
			dp[i][l]=dp[i-1][l];
		}
		j=1;
		while(a[i]-a[j]>5)
			j++;
		//cout<<j<<endl;
		f(l,1,k+1){
			dp[i][l]=max(dp[i][l],dpp(j-1,l-1)+i-j+1);
			//cout<<dp[i][l]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[n][k];
}