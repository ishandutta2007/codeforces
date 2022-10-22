#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define LL long long
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
	if(x>9) Out(x/10);
	putchar('0'+x%10);
}
LL mul(LL x,LL y,LL mod){
	return (x*y-(LL)((long double)x/mod*y+1e-8)*mod+mod)%mod;
} 
LL qpow(LL x,LL y,LL mod){
	LL re=0;
	while(y){
		if(y&1) re=(re+x)%mod;
		x=(x+x)%mod;y>>=1;
	}
	return re;
}
const int N=1e5+10;
int n,m,k,tp=0;
int q[N];
int a[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int l=0;
	for(int i=2;i<=n;++i)
		q[++tp]=a[i]-a[i-1]-1;
	sort(q+1,q+1+tp);
	int ans=n;
	for(int i=1;i<=n-k;++i){
		ans+=q[i];
	}
	printf("%d\n",ans);
	return 0;
}