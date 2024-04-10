#include<cstdio>
#include<cctype>
#include<algorithm>

#define maxn 202202
#define mod 998244353

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

bool s[maxn];

int n,x[maxn],y[maxn];

long long f[maxn],g[maxn],sum[maxn];

int main(){
    n=read<int>();
    for(int i=1;i<=n;i++){
	x[i]=read<int>();
	y[i]=read<int>();
	s[i]=read<int>();
	int nxt=std::lower_bound(x+1,x+1+i,y[i])-x;
	g[i]=(x[i]-y[i]+sum[i-1]+mod-sum[nxt-1])%mod;
	f[i]=(f[i-1]+x[i]-x[i-1])%mod;
	if(s[i])(f[i]+=g[i])%=mod;
	sum[i]=(sum[i-1]+g[i])%mod;
    }
    printf("%lld\n",(f[n]+1)%mod);
    return 0;
}