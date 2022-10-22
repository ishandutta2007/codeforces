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
const int N=505,mod=1e9+7;
ll n,g[N][N],dp[N][N][2];
int main(){
	cin>>n;
	f(i,0,n) f(j,0,n) get(g[i][j]);
	f(i,0,n) dp[i][i][0]=1;
	f(i,1,n){
		f_(j,i-1,0){
			f(l,j,i)
				dp[j][i][1]=(dp[j][i][1]+((dp[j][l][0]*dp[l+1][i][0])%mod))%mod;
			f(l,j+1,i+1){
				if(g[j][l]==1)
					dp[j][i][0]=(dp[j][i][0]+((dp[j][l][1]*dp[l][i][0])%mod))%mod;
			}
		}
	}
	cout<<dp[0][n-1][0];
}