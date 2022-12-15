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
int n,m,ss,cc;
int t[230001],o[109];
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;++i)t[i]=read();
	for(int i=1;i<=n;++i){
		cc=m-t[i]; ss=0;
		for(int i=1;i<=100;++i){
			if(cc>=i*o[i]){
				ss+=o[i];
				cc-=i*o[i];
				continue;
			}
			ss+=cc/i;
			break;
		}
		++o[t[i]];
		printf("%d ",i-1-ss);
	}
}