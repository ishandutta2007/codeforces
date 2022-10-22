#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e6+9;
const int mod=1e9+7;
int n;
int a[M];
void OR(int *dp,int o){
	for(int k=1;k<1<<17;k<<=1){
		for(int i=0;i<1<<17;i+=k<<1){
			for(int j=0;j<k;++j){
				dp[i+j+k]=(1ll*dp[i+j+k]+dp[i+j]*o%mod+mod)%mod;
			}
		}
	}
}
void AN(int *dp,int o){
	for(int k=1;k<1<<17;k<<=1){
		for(int i=0;i<1<<17;i+=k<<1){
			for(int j=0;j<k;++j){
				dp[i+j]=(1ll*dp[i+j]+dp[i+j+k]*o%mod+mod)%mod;
			}
		}
	}
}
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
void XO(int *dp,int o){
	for(int k=1;k<1<<17;k<<=1){
		for(int i=0;i<1<<17;i+=k<<1){
			for(int j=0;j<k;++j){
				int x=dp[i+j],y=dp[i+j+k];
				dp[i+j]=1ll*(dp[i+j]+y)%mod*o%mod;
				dp[i+j+k]=1ll*(x-dp[i+j+k]+mod)%mod*o%mod;
			}
		}
	}
}
int dpa[19][M],dp[19][M],Dpa[M],dpb[M],dpc[M],f[M];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		dpa[__builtin_popcount(a[i])][a[i]]++;
		dpb[a[i]]++;
		dpc[a[i]]++;
	}
	for(int j=0;j<19;++j){
		OR(dpa[j],1);
	}
	for(int j=0;j<19;++j){
		for(int k=0;k<19;++k){
			if(j+k<19){
				for(int i=0;i<1<<17;++i){
					dp[j+k][i]=(dp[j+k][i]+1ll*dpa[j][i]*dpa[k][i]%mod)%mod;
				}
			}
		}
	}
	for(int j=0;j<19;++j){
		OR(dp[j],-1);
	}
	for(int i=0;i<1<<17;++i){
		Dpa[i]=dp[__builtin_popcount(i)][i];
	}
	XO(dpc,1);
	for(int i=0;i<1<<17;++i)dpc[i]=1ll*dpc[i]*dpc[i]%mod;
	XO(dpc,kpow(2,mod-2));
	f[1]=1;
	for(int i=2;i<1<<17;++i){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	for(int i=0;i<1<<17;++i){
		Dpa[i]=1ll*Dpa[i]*f[i]%mod;
		dpb[i]=1ll*dpb[i]*f[i]%mod;
		dpc[i]=1ll*dpc[i]*f[i]%mod;
	}
	AN(Dpa,1);
	AN(dpb,1);
	AN(dpc,1);
	int ans=0;
	for(int i=0;i<1<<17;++i)Dpa[i]=1ll*Dpa[i]*dpb[i]%mod*dpc[i]%mod;
	AN(Dpa,-1);
	for(int i=0;i<17;++i)ans=(ans+Dpa[1<<i])%mod;
	cout<<ans<<"\n";
	return 0;
}