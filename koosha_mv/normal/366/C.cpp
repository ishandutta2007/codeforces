#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int a[109],b[109],dp[101][200010],n,k,mid=200010/2,mx;
int main(){
	cin>>n>>k;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){cin>>b[i];a[i]=a[i]-(b[i]*k);}
	f(l,1,n+1){
		f_(i,200010,0){
			if(dp[l-1][i]>0) dp[l][i]=dp[l-1][i];
			if(i-a[l]>0 && i-a[l]<200010 && dp[l-1][i-a[l]]>0){dp[l][i]=max(dp[l][i],dp[l-1][i-a[l]]+b[l]); }
			if(i-a[l]==mid){dp[l][i]=max(dp[l][i],dp[l-1][i-a[l]]+b[l]);}
			//if(abs(i-mid)<20) cout<<dp[l][i]<<" ";
		}
		//cout<<endl;
	}
	f(i,1,n+1) mx=max(mx,dp[i][mid]);
	cout<<(!(mx>0))*-1+mx*k;
}