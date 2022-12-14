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
int ss,n,d,a[205];
char s[205];
int main()
{
	n=read();scanf("%s",s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]-48;
	for(int i=0;i<=900;++i){
		ss=0;d=0;
		for(int j=1;j<=n;++j){
			ss=ss+a[j];
			if(ss==i){
				++d;
				ss-=i;
			}
		}
		if(d>=2&&!ss){
				puts("YES");
				exit(0);
			}
	}
	puts("NO");
}