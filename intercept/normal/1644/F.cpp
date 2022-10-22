#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,k;
int vis[M],dp[M],a[M],sum;
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
int get(int x){
	if(vis[x]!=-1)return vis[x];
	int t=min(x,k);
	a[0]=0;
	for(int i=1;i<=t;++i){
		a[i]=(a[i-1]+1ll*kpow(i,x)*inv[i]%mod)%mod;
	}
	int rex=0;
	for(int i=0,o=1;i<=t;++i){
		rex=(1ll*rex+mod+1ll*o*inv[i]*a[t-i]%mod)%mod;
		o*=-1;
	}
	return vis[x]=rex;
}
int main(){
	pre();
	cin>>n>>k;
	k=min(n,k);
	if(k==1||n==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;++i)vis[i]=-1;
	int sum=get(n)-1;
	dp[n]=1;
	for(int i=n-1;i>=2;--i){
		dp[i]=get((n-1)/i+1)-1;
		for(int j=i+i;j<n;j+=i){
			dp[i]=(dp[i]+mod-dp[j])%mod;
		}
		sum=(sum+mod-dp[i])%mod;
	}
	cout<<sum<<endl;
	return 0;
}
/*
1
3 5
-2 -7 -1
*/