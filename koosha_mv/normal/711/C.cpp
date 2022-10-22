#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll e1=1e18,mn=1e18,n,m,k,a[109],dp[109][109][109],col[109][109];
int main(){
	cin>>n>>m>>k;
	f(i,1,n+1){
		cin>>a[i];}
	f(i,1,n+1){
		f(j,1,m+1){
			cin>>col[i][j];
			if(a[i]!=0)
				col[i][j]=1e18;
		}
		if(a[i]!=0){
			col[i][a[i]]=0;	
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
			dp[i][j][0]=1e18;	
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
		 	f(k1,1,k+1){
		 		dp[i][j][k1]=1e18;
				dp[i][j][k1]=dp[i-1][j][k1]+col[i][j];
				//cout<<i<<" "<<j<<" "<<k1<<" : "<<dp[i][j][k1]<<endl;
				f(l,1,m+1){
					if(l!=j && k1-1>0){
						dp[i][j][k1]=min(dp[i][j][k1],dp[i-1][l][k1-1]+col[i][j]);
					//	cout<<dp[i-1][l][k1-1]<<" ";
					}
				}
				if(i==1 && k1>1){
					dp[i][j][k1]=1e18;
				}
				dp[i][j][k1]=min(dp[i][j][k1],e1);
				//cout<<i<<" "<<j<<" "<<k1<<" : "<<dp[i][j][k1]<<endl;
				if(i==n && k1==k)
					mn=min(mn,dp[i][j][k1]);
			}
			}
		}
	cout<<mn-(mn>=1e18)*(mn+1);
}