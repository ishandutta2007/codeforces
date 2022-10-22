#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll dp[2][102][51],n,ts,mx=0;
string s;
int main(){
	cin>>s>>n;ts=s.size();
	f(i,1,n+1){dp[0][0][i]=-(1e18),dp[1][0][i]=-(1e18);}dp[1][0][0]=-(1e18);
	f(i,1,ts+1){
		f(j,0,n+1){
			dp[0][i][j]=-(1e18),dp[1][i][j]=-(1e18);
			if(s[i-1]=='F'){
				dp[0][i][j]=dp[0][i-1][j]+1;
				dp[1][i][j]=dp[1][i-1][j]-1;
				if(j>0){
					dp[0][i][j]=max(dp[0][i][j],dp[1][i-1][j-1]);
					dp[1][i][j]=max(dp[1][i][j],dp[0][i-1][j-1]);
				}
			}
			else{
				dp[0][i][j]=dp[1][i-1][j];
				dp[1][i][j]=dp[0][i-1][j];
				if(j>0){
					dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-1]+1);
					dp[1][i][j]=max(dp[1][i][j],dp[1][i-1][j-1]-1);}}
		}
	}
	for(int i=n;i>=0;i-=2) mx=max(mx,max(dp[0][ts][i],dp[1][ts][i]));
	mx=max(mx,max(dp[0][ts][n],dp[1][ts][n]));
	f(i,1,n+1){dp[0][0][i]=-(1e18),dp[1][0][i]=-(1e18);}dp[0][0][0]=-(1e18),dp[1][0][0]=0;
	f(i,1,ts+1){
		f(j,0,n+1){
			dp[0][i][j]=-(1e18),dp[1][i][j]=-(1e18);
			if(s[i-1]=='F'){
				dp[0][i][j]=dp[0][i-1][j]+1;
				dp[1][i][j]=dp[1][i-1][j]-1;
				if(j>0){
					dp[0][i][j]=max(dp[0][i][j],dp[1][i-1][j-1]);
					dp[1][i][j]=max(dp[1][i][j],dp[0][i-1][j-1]);
				}
			}
			else{
				dp[0][i][j]=dp[1][i-1][j];
				dp[1][i][j]=dp[0][i-1][j];
				if(j>0){
					dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-1]+1);
					dp[1][i][j]=max(dp[1][i][j],dp[1][i-1][j-1]-1);
				}
			}
		}
	}
	for(int i=n;i>=0;i-=2) mx=max(mx,max(dp[0][ts][i],dp[1][ts][i]));
	cout<<mx;
}