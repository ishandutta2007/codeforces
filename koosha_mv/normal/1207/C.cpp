#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+99;
long long dp[N][2];
string s;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,x,y;
		cin>>n>>x>>y;
		cin>>s;
		for(int i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=1e18;
		dp[0][0]=y;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{	
				dp[i][1]=min(dp[i-1][1]+2*y+x,dp[i-1][0]+2*y+2*x);
				dp[i][0]=min(dp[i-1][1]+y+2*x,dp[i-1][0]+y+x);
			}
			else
				dp[i][1]=dp[i-1][1]+2*y+x;
		}	
		cout<<dp[n][0]<<endl;
	} 
}