#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret*f;
}
#define N 300005
int a[N],ma,T,n;
int main()
{
	T=read();
	while(T--){
		n=read();for(int i=1;i<=n;++i)a[i]=read();
		ma=1;
		for(int i=2;i<=n;++i)if(a[i]>a[ma]){
			ma=i;
		} else {
			if(a[ma]-a[i]>=i-ma+1){
				puts("YES");printf("%d %d\n",ma,i);goto lll;
			}
			if(a[ma]-a[i]<i-ma)ma=i;
		}
		
		ma=n;
		for(int i=n-1;i;--i)if(a[i]>a[ma]){
			ma=i;
		} else {
			if(a[ma]-a[i]>=ma-i+1){
				puts("YES");printf("%d %d\n",i,ma);goto lll;
			}
			if(a[ma]-a[i]<ma-i)ma=i;
		}
		puts("NO");
		lll:;
	}
}