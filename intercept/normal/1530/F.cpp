#include<bits/stdc++.h>
using namespace std;
const int M=1<<23;
const int mod=31607;
int n,S;
int a[24],dp[M],f[M],ina[24],Pw[M<<1];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=x*x%mod)if(y&1)rex=rex*x%mod;
	return rex;
}
int inv=kpow(10000,mod-2);
void fwt(int *b){
	for(int o=1;o<S;o<<=1){
		for(int j=0;j<S;j+=o<<1){
			for(int k=0;k<o;++k){
				b[j+k]+=b[j+k+o];
				if(b[j+k]>=mod)b[j+k]-=mod;
			}
		}
	}
}
void dfwt(int *b){
	for(int o=1;o<S;o<<=1){
		for(int j=0;j<S;j+=o<<1){
			for(int k=0;k<o;++k){
				b[j+k]-=b[j+k+o];
				if(b[j+k]<0)b[j+k]+=mod;
			}
		}
	}
}
int pw(int x){return Pw[x&-x];}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=23;++i)Pw[1<<i]=i;
	S=1<<n+2;
	dp[S-1]=1;
	fwt(dp);
	for(int i=1;i<=n;++i){
		f[0]=1;
		for(int j=0;j<n;++j){
			scanf("%d",&a[j]);
			a[j]=a[j]*inv%mod;
			ina[j]=kpow(mod+1-a[j],mod-2);
			f[0]=f[0]*(mod+1-a[j])%mod;
		}
		for(int j=1,T=(1<<n);j<T-1;++j){
			f[j]=1ll*f[j^(j&-j)]*a[pw(j)]*ina[pw(j)]%mod;
		}
		for(int j=1,T=(1<<n);j<T-1;++j){
			int x=j;
			if(x>>(i-1)&1)x|=T;
			if(x>>(n-i)&1)x|=T<<1;
			if(x!=j)f[x]=f[j],f[j]=0;
		}
		fwt(f);
		for(int j=0;j<S;++j){
			dp[j]=dp[j]*f[j]%mod;
			f[j]=0;
		}
	}
	dfwt(dp);
	printf("%d\n",(mod+1-dp[0])%mod);
	return 0;
}