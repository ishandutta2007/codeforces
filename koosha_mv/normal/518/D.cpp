#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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
const int N=2005;
int n,t;
double p,p2,dp[N][N],ans;
int main(){
	cout.precision(16);
	cin>>n>>p>>t;
	p2=1-p;
	dp[0][0]=1;
	f(i,1,t+1){
		f(j,0,n)
			dp[i][j]=dp[i-1][j-1]*p+(dp[i-1][j]*p2);
		dp[i][n]=dp[i-1][n-1]*p+dp[i-1][n];
	}
	f(i,1,n+1)
		ans+=i*dp[t][i];
	cout<<ans;
}