#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=998244353;
int a[maxn];
int tp,st[maxn];
int g[maxn],sum0[maxn],sum1[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int calc(int l,int r,int op){
	if(l>r)return 0;
	int s0=sub(sum0[r]-sum0[l-1]),s1=sub(sum1[r]-sum1[l-1]);
	return sub(op?(s1-s0):(s0-s1));
}
int main(){
//    freopen("CF1585.in","r",stdin);
//    freopen("CF1585.out","w",stdout);
    int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	g[1]=a[1]%mod,sum1[1]=a[1]%mod,st[++tp]=1;
	for(int i=2;i<=n;i++){
		g[i]=1ll*(a[i]-1)*g[i-1]%mod;
		int pre=i-1,op=(i&1),val;
		while(tp&&a[i]<a[st[tp]]){
			int j=st[tp],k=st[tp-1];tp--;pre=j;
			if(!tp)break;
			g[i]=add(g[i]+1ll*sub(a[j]-a[i])*calc(k,j-1,op)%mod);
		}
		val=sub(a[pre]-a[i]);
		if(!tp)
			g[i]=add(g[i]+1ll*sub(a[pre]-a[i])*calc(1,pre-1,op)%mod),
			g[i]=op?sub(g[i]-val):add(g[i]+val);
		st[++tp]=i;
		sum0[i]=sum0[i-1],sum1[i]=sum1[i-1];
		if(i&1)sum1[i]=add(sum1[i]+g[i]);else sum0[i]=add(sum0[i]+g[i]);
	}
	printf("%d\n",g[n]);
    return 0;
}