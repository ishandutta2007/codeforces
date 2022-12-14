#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define WQY 22500
int g[30002],h[30024],t,n;  ///\n 0     //r //\//
int main()
{
//	putchar('33');
	t=read();
	for(int i=1;i<=WQY;++i){
		g[i]=(i*2)*(i*2-1)/2;
	}
	while(t--){
		n=read();
		for(int i=WQY;i;--i){
			h[i]=n/g[i];
			n%=g[i];
		}
		putchar('1');
		for(int i=1;i<=WQY;++i){
			putchar('3');putchar('3');
			for(int j=1;j<=h[i];++j)putchar('7');
		}
		puts("");
	} 
}