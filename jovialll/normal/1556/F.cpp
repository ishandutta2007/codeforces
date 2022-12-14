#include<bits/stdc++.h>
using namespace std;
#define N 15
#define ll long long
#define mod 1000000007
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
ll dp[1<<N],ans,F[1<<N],a[N],ny[N][N],sz[1<<N],f[1<<N],n,i,j;
ll cal(int st1,int st2){
	ll ret=1;int i,j;
	for(i=0;i<n;++i){
		if((st1>>i)&1){
		for(j=0;j<n;++j){
			if((st2>>j)&1){
				(ret*=ny[i][j])%=mod;
			}
		}
		}
	}
	cout<<st1<<" "<<st2<<" "<<ret<<' '<<F[st1]<<" "<<F[st2]<<"\n";
	return ret*(ksm(F[st1],sz[st2])%mod+ksm(F[st2],sz[st1]))%mod;
}
ll CAL(int st1,int st2){
	ll ret=1;
	int i,j;
	for(i=0;i<n;++i){
		if((st1>>i)&1){
		for(j=0;j<n;++j){
			if((st2>>j)&1){
				(ret*=ny[i][j])%=mod;
			}
		}
		}
	}
	return ret*ksm(F[st1],sz[st2])%mod;
}
int mx,x,f1;
signed main(){
	cin>>n;
	for(i=0;i<n;++i)cin>>a[i];
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			ny[i][j]=ksm(a[i]+a[j],mod-2);
		}
	}
	for(i=0;i<(1<<n);++i){
		F[i]=1;
		for(j=0;j<n;++j){
			if((i>>j)&1)(F[i]*=a[j])%=mod,++sz[i];
		}
	}
	mx=(1<<n)-1;
	for(i=1;i<(1<<n);++i){
		f[i]=1;
		x=(i&-i);
		for(j=i&(i-1);j;j=(j-1)&i)
			(f[i]-=f[j]*CAL(j,i^j))%=mod;
	}
	dp[0]=1;
	for(i=0;i<mx;++i){
		f1=i^mx;
		(ans+=CAL(f1,i)%mod*f[f1]%mod*sz[f1])%=mod;
	}
	cout<<(ans+mod)%mod;
}