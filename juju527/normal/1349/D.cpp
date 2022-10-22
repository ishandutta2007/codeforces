#include <bits/stdc++.h>
using namespace std;
const int maxn=5e6+5,maxm=1e7+5,mod=998244353;
int a[maxn];
int g[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
int main(){
//    freopen("game.in","r",stdin);
//    freopen("game.out","w",stdout);
   	int n,m=0;
	n=read();
	for(int i=1;i<=n;i++){a[i]=read();m+=a[i];}
	g[0]=n-1;
	g[m]=0;
	for(int i=1;i<m;i++)g[i]=1ll*(1ll*m*(n-1)%mod+1ll*i*(n-1)%mod*g[i-1]%mod)*power(m-i,mod-2)%mod;
	for(int i=m-1;i>=0;i--)g[i]=(g[i]+g[i+1])%mod;
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+g[a[i]])%mod;
	ans=(ans-1ll*g[0]*(n-1)%mod+mod)%mod;
	printf("%lld\n",1ll*ans*power(n,mod-2)%mod);
    return 0;
}