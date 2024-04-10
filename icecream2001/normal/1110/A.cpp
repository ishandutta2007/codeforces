#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
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
int b,k;
int a[N];
int main(){
	scanf("%d%d",&b,&k);
	int s=0,x=1;
	for(int i=1;i<=k;++i){
		scanf("%d",&a[i]);
	}
	for(int i=k;i>=1;--i){
		s=s+a[i]*x;
		s=s&1;
		x=x*b;
		x=x&1;
	}
	if(s) puts("odd");
	else puts("even");
	return 0;
}