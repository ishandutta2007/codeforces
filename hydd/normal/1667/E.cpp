#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,m; ll fac[210000],inv[210000],ans[210000];
int C(int n,int m){//n>=m
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	fac[0]=1; for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=200000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=200000;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	cin>>n; m=((n+1)>>1); ll sum=0;
	for (int u=m;u>=2;u--){
		ll tmp=fac[n-u]*fac[u-2]%Mod*C(m-1,u-1)%Mod;
		ans[u]=(tmp*(u-1)+Mod-sum)%Mod; sum=(sum+tmp)%Mod;
	}
	ans[1]=(fac[n-1]+Mod-sum)%Mod;
	for (int u=1;u<=n;u++) cout<<ans[u]<<' ';
	return 0;
}