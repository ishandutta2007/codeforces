#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n; ll k;
ll fac[210000],inv[210000];
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
ll C(int n,int m){ return fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
ll S(int n,int m){
	ll res=0;
	for (int k=0;k<=m;k++)
		if (k&1) res=(res+(Mod-C(m,k))*qpow(m-k,n))%Mod;
		else res=(res+C(m,k)*qpow(m-k,n))%Mod;
	return res*inv[m]%Mod;
}
int main(){
	scanf("%d%lld",&n,&k);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	if (k==0) printf("%lld\n",fac[n]);
	else if (k>n) puts("0");
	else printf("%lld\n",S(n,n-k)*C(n,n-k)%Mod*fac[n-k]%Mod*2%Mod);
	return 0;
}