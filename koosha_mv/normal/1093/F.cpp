#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define m(x) x=x%mod;

const int N=1e5+9,mod=998244353;

ll sm,n,len,k,a[N],p,dp[N][102],g[N][102],mark[109];

int main(){
	cin>>n>>k>>len;k++;
	dp[0][0]=1;dp[0][k]=1;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){
		mark[a[i]+(a[i]==-1)]++;
		if(i-len>=0)
			mark[a[i-len]]--;
		sm=0;
		f(j,1,k+1)
			sm+=mark[j];
		f(j,1,k+1){
			if(sm-mark[j]>0)
				g[i][j]=1;
		}
	}
	f(i,1,n+1){
		p=dp[i-1][0];
		if(i-len>=0){
			f(j,1,k+1){
				p=(p+mod-dp[i-len][j])%mod;
				dp[i][j]=(dp[i][j]+dp[i-len][j])%mod;
			}
		}
		f(j,1,k){
			dp[i][j]=(dp[i][j]+p)%mod;
			if(g[i][j]==1)
				dp[i][j]=dp[i-1][0];
			dp[i][j]*=(a[i]==-1 || a[i]==j);
			dp[i][0]=(dp[i][0]+dp[i][j])%mod;
		}
		dp[i][k]=0;
	}
	cout<<dp[n][0];
}