#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=505;
ll n,dp[N][N][2];
string s;
int main(){
	cin>>n>>s;
	f(i,0,n) dp[i][i][0]=dp[i][i][1]=1;
	f(i,1,n){
		f_(j,i-1,0){
			dp[j][i][0]=1e9;
			f(k,j,i+1)
				minm(dp[j][i][0],dp[j][k][0]+dp[k+1][i][0]);
			dp[j][i][1]=1e18;
			if(s[j]==s[i]){
				f(k,j+1,i+1)
					minm(dp[j][i][1],dp[k][i][1]+dp[j+1][k-1][0]);
				minm(dp[j][i][0],dp[j][i][1]);
			}
		}
	}
	cout<<dp[0][n-1][0]<<endl;
}