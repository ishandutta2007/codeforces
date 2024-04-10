// Hydro submission #62fa3b874b7288bafe5ee8db@1660566407769
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
const int mod=998244353;
int D, q, cnt, d[1000], fac[100];
int fp(int a,int b) {
	int c=1;
	for(;b;a=a*a%mod,b>>=1) if(b&1) c=c*a%mod;
	return c;
}
int calc(int x) {
	int p=0, q=1;
	for(int i=1;i<=cnt;++i) if(x%d[i]==0) {
		int e=0;
		while(x%d[i]==0) x/=d[i], ++e;
		p+=e, (q*=fac[e])%=mod;
	}
	return fac[p]*fp(q,mod-2)%mod;
}
int gcd(int x,int y) { return y? gcd(y,x%y):x; }
signed main() {
	D=read(), q=read();
	for(int i=2;i*i<=D;++i) if(D%i==0) {
		while(D%i==0) D/=i;
		d[++cnt]=i;
	}
	if(D>1) d[++cnt]=D;
	fac[0]=fac[1]=1;
	for(int i=2;i<=100;++i) fac[i]=fac[i-1]*i%mod;
	while(q--) {
		int x=read(), y=read();
		int z=gcd(x,y);
		printf("%lld\n",calc(x/z)*calc(y/z)%mod);
	}
}