#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
long long dp[300099][3];
int main(){
	long long gh,pq,n,x,y;cin>>pq;
	f(salam,0,pq){
		scanf("%I64d",&n);
		gh=-3;
		f(i,0,n){
			scanf("%I64d%I64d",&x,&y);
			dp[i][0]=1e18;dp[i][1]=1e18;dp[i][2]=1e18;
			if(i!=0){
			f(j,0,3){
				if(gh!=x+j){
					dp[i][j]=min(dp[i][j],dp[i-1][0]);
				}
				if(gh+1!=x+j){
					dp[i][j]=min(dp[i][j],dp[i-1][1]);
				}
				if(gh+2!=x+j){
					dp[i][j]=min(dp[i][j],dp[i-1][2]);
				}
			}
			dp[i][1]+=y;
			dp[i][2]+=2*y;
			}
			else{
				dp[i][0]=0;
				dp[i][1]=y;
				dp[i][2]=y*2;
			}
			gh=x;
		}
		cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
	}
}