//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define N 5009
using namespace std;
typedef long long ll;
const int mod=998244353;
ll dp[N][2509];
ll jie[N],ni[N];
int n;
int a[N],sum[N];
inline void MOD(ll &x){x=x>=mod?x-mod:x;}
inline ll power(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
inline ll C(int n,int m){
	return jie[n]*ni[m]%mod*ni[n-m]%mod;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	reverse(a+1,a+n+1);
	int p=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1]){
		    ++p;
			sum[p]=sum[p-1]+1;
		}
		else{
			sum[p]++;
		}
	}
	for(int i=1;i<=p;++i)
	    for(int j=0;j<=n/2;++j)
	    	dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=p;++i){
		for(int j=0;j<=p&&j<=n/2;++j)if(dp[i-1][j]){
			int tt=sum[i]-sum[i-1];
			int qq=j-1-(sum[i-1]-j);
		//	cout<<qq<<endl;
			if(j==n/2)qq++;
			if(tt==1)MOD(dp[i][j+1]+=dp[i-1][j]);
			else if(qq>=tt-1)MOD(dp[i][j+1]+=dp[i-1][j]*C(qq,tt-1)%mod);
			if(qq>=tt)MOD(dp[i][j]+=dp[i-1][j]*C(qq,tt)%mod);
		//	cout<<qq<<endl;
		//	cout<<i-1<<" "<<j<<" "<<dp[i-1][j]<<" "<<dp[i][j+1]<<" "<<dp[i][j]<<" "<<qq<<endl;
		}
	}
	printf("%lld\n",dp[p][n/2]);
}
int main(){
	int T;
	scanf("%d",&T);
	jie[0]=1;
	for(int i=1;i<=5000;++i)jie[i]=jie[i-1]*i%mod;
	ni[5000]=power(jie[5000],mod-2);
	for(int i=4999;i>=0;--i)ni[i]=ni[i+1]*(i+1)%mod;
	while(T--){
		solve();
	}
	return 0;
}