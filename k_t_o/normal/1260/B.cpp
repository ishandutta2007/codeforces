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
int T,a,b;
int main()
{
	T=read();
	while(T--){
		a=read(),b=read();
		if((a+b)%3){
			puts("NO");continue;
		}
		if(a>b*2||b>a*2){
			puts("NO");continue;
		}
		puts("YES");
	} 
}