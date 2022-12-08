#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const int N=1e5+100,mod=1e9+7;
int n,q,cnt[55],dp[N],f[N],fac[N],inv[N],res[55][55]; char s[N];
int id(char c){
	return 'A'<=c&&c<='Z'?c-'A':c-'a'+26;
}
int ksm(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) s=(ll)s*x%mod;
	return s;
}
void init(int n){
	fac[0]=1;
	rep (i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for (int i=n-1;~i;i--) inv[i]=(ll)inv[i+1]*(i+1)%mod;
}
int main(){
	scanf("%s%d",s+1,&q); n=strlen(s+1); init(n);
	rep (i,1,n) cnt[id(s[i])]++;
	dp[0]=1;
	rep (i,0,51) if (cnt[i])
		for (int j=n/2;j>=cnt[i];j--) dp[j]=(dp[j]+dp[j-cnt[i]])%mod;
	int v=(ll)fac[n/2]*fac[n/2]%mod;
	rep (i,0,51) v=(ll)v*inv[cnt[i]]%mod;
	rep (x,0,51) rep (y,0,51){
		rep (i,0,n/2) f[i]=dp[i];
		rep (i,cnt[x],n/2) f[i]=(f[i]+mod-f[i-cnt[x]])%mod;
		if (x!=y)
			rep (i,cnt[y],n/2) f[i]=(f[i]+mod-f[i-cnt[y]])%mod;
		res[x][y]=(ll)f[n/2]*v%mod*2%mod;
	}
	while (q--){
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",res[id(s[x])][id(s[y])]);
	}
	return 0;
}