#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=1000000007;
typedef long long ll;
ll ans;
int n;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
ll qpow(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read();
	ans=1;
	for(register int i=1;i<=n;++i)
		ans=ans*i%mod;
	printf("%lld",(ans-qpow(2,n-1)+mod)%mod);
	return 0;
}