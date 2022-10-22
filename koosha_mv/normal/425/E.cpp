#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define Add(x,y) x=(x+y)%mod

const int N=501,mod=1e9+7;

int Pow[N*N],dp[N][N];

int main(){
	Pow[0]=1;
	f(i,1,N*N) Pow[i]=2ll*Pow[i-1]%mod;
	f(i,0,N) dp[i][0]=1;
	
	f(n,1,N)
		f(k,1,n+1)
			f(last,1,n+1)
				Add(dp[n][k],1ll*dp[last-1][k-1]*Pow[(last-1)*(n-last+1)]%mod*(Pow[n-last+1]-1)%mod);
	int n,k;
	cin>>n>>k;
	cout<<dp[n][k];
}