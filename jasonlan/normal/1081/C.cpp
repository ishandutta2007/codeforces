#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2010,mod=998244353;
int n,m,k;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int a,int b){
	int p[a+1];
	p[0]=1;
	for(register int i=1;i<=a;++i)
		p[i]=1ll*p[i-1]*i%mod;
	return 1ll*p[a]*qpow(p[b],mod-2)%mod*qpow(p[a-b],mod-2)%mod;
}
int main()
{
	n=read();m=read();k=read();
	printf("%lld",1ll*m*qpow(m-1,k)%mod*C(n-1,k)%mod);
	return 0;
}