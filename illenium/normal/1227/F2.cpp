#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
#define p 998244353
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

inline ll qpow(int a,int b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%p;
		b>>=1; base=(base*base)%p;
	}
	return ans;
}

ll fac[maxn],inv[maxn],n,k,a[maxn],cnt,z;

inline ll C(int n,int m)
{
	return (((fac[n]*inv[m])%p)*inv[n-m])%p;
}

int main()
{
	n=read(); k=read(); fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
	for(int i=0;i<=n;i++) inv[i]=qpow(fac[i],p-2); z=qpow(2,p-2);
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) cnt++;
	if(a[1]!=a[n]) cnt++;
	ll ans=0,tmp=qpow(k,n);
	for(int i=0;i*2<=cnt;i++)
	{
		ans=(ans+(C(cnt,i)*C(cnt-i,i)%p)*qpow((k-2),cnt-2*i))%p;
	}
	ans=(ans*qpow(k,n-cnt))%p;
	cout<<((tmp-ans+p)%p*z)%p;
	return 0;
}