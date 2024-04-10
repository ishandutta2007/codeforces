#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=21,mod=1e9+7;
typedef long long ll;
int n;
ll a[maxn],mp[maxn],s,ans;
inline ll read(){
	ll res=0;
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
ll C(ll x,ll y){
	if(x<0||y<0||x<y)return 0;
	ll res=1;
	for(register int i=0;i<y;++i)
		res=res*((x-i)%mod)%mod;
	return res*mp[y]%mod;
}
void reset(){
	ll res=1;
	for(register int i=1;i<=n;++i)
		res=res*i%mod;
	mp[n]=qpow(res,mod-2);
	for(register int i=n-1;~i;--i)
		mp[i]=mp[i+1]*(i+1)%mod;
}
int main(){
	n=read();s=read();
	for(register int i=0;i<n;++i)
		a[i]=read();
	reset();
	for(register int i=0;i<1<<n;++i){
		bool flag=true;
		ll x=0;
		for(register int j=0;j<n;++j)
			if((i>>j)&1)x+=a[j]+1,flag^=1;
		ans+=flag?C(n+s-x-1,n-1):mod-C(n+s-x-1,n-1);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}