#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2009;
int n,m,k;
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int dp[M][M];
void work(){
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1,rex=1;i<=min(k,n);++i){
		rex=1ll*rex*(n-i+1)%mod*inv[i]%mod*fac[i-1]%mod;
		ans=(ans+1ll*rex*dp[i][k]%mod*kpow((m+1)/2,i)%mod*kpow(m,n-i)%mod)%mod;
	}
	cout<<ans<<endl;
}
int main(){
	pre();
	dp[0][0]=1;
	for(int kk=1;kk<=2000;++kk){
		for(int i=1;i<=kk;++i){
			dp[i][kk]=(1ll*dp[i][kk-1]*i%mod+1ll*dp[i-1][kk-1]*i%mod);
		}
	}
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4
0 10 10 10
10 10 10 10
*/