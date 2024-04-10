#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long i,j,k;
int n,m,x;
const long long mod=1e9+7;
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1; t3=t3*t2%mod;
		}
		t1=t1*2; t2=t2*t2%mod;
	}
	return t3;
}
const int maxn=3*(1e6+10);
long long P[maxn],niP[maxn];
long long C(long long n,long long m){
	if (m>n) return 0;
	return P[n]*niP[m]%mod*niP[n-m]%mod;
}
long long f[maxn],g[maxn];
int main(){
	
	P[0]=1; for (i=1;i<maxn;i++) P[i]=P[i-1]*i%mod;
	niP[maxn-1]=getax(P[maxn-1],mod-2);
	for (i=maxn-2;i>=0;i--) niP[i]=niP[i+1]*(i+1)%mod;
	
	n=read(); m=read();
	
	for (i=0;i<=3*n+3;i++){
		f[i]=C(3*n+3,i);
	}
	
	f[0]=(f[0]-1+mod)%mod;
	f[1]=(f[1]-3+mod)%mod;
	f[2]=(f[2]-3+mod)%mod;
	f[3]=(f[3]-1+mod)%mod;
	
	for (i=3*n+3;i>=0;i--){
		if (f[i]){
			f[i-1]=(f[i-1]-3*f[i]+mod*mod)%mod;
			f[i-2]=(f[i-2]-3*f[i]+mod*mod)%mod;
			g[i-3]=f[i]; f[i]=0;
		}
	}
	
	for (i=1;i<=m;i++){
		x=read();
		printf("%lld\n",g[x]);
	}

	return 0;
}
/*

C(3i,x)+C(3i+3,x)+C(3i+6,x)

1
11
121
1331
14641
111111

dp[n][m]=dp[n-1][m]+3dp[n-1][m-1]+3dp[n-1][m-2]+dp[n-1][m-3]
dp[n]=(1+3X+3X^2+X^3)dp[n-1];

for (i=1;i<=n;i++) sigma((1+x)^3i)

f = (1+x)^3 (1+x)^6 (1+x)^9
(1+x)^3f =  (1+x)^6 (1+x)^9 (1+x)^12
f=((1+x)^3n-(1+x)^3)/((1+x)^3-1) 
((1+x)^3-1)=x^3+3x^2+3x

 1331
  121
   11
    1
*/