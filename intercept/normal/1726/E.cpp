#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n;
int inv[M],fac[M],p[M],dp[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
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
    p[2]=1;
	for(int i=4;i<M;i+=2)p[i]=1ll*p[i-2]*(i-1)%mod;
	dp[0]=dp[1]=1;
	for(int i=2;i<M;++i){
		dp[i]=(dp[i-1]+1ll*(i-1)*dp[i-2]%mod)%mod;
	}
}
void work(){
	cin>>n;
	int ans=dp[n];
	for(int i=2;i*2<=n;i+=2){
		ans=(ans+1ll*kpow(2,i/2)*c(n-i,i)%mod*p[i]%mod*dp[n-2*i]%mod)%mod;
	}
	cout<<ans<<endl;
}
int main(){
	pre();
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5


*/