#include<bits/stdc++.h>
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

int cal(int x){
	int re=1;
	while(re<x) re=(re<<1)|1;
	return re;
}
int main(){
	int T;scanf("%d",&T);
	int x;
	while(T--){
		scanf("%d",&x);
		if(x==1){
			puts("1");
			continue;
		}
		int y=cal(x),z=1;
		if(y==x){
			for(int i=2;i<=sqrt(x);++i){
				if(x%i==0){
					z=max(z,x/i);
					z=max(z,i);
				}
			}
			printf("%d\n",z);
		}
		else{
			printf("%d\n",y);
		}
	}
	return 0;
}