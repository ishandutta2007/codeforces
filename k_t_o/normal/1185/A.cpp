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
int a,b,c,d;
int main()
{
	a=read();b=read();c=read(); d=read();
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	if(a<b-d)a=b-d;
	if(c>b+d)c=b+d;
	printf("%d",a-(b-d)+b+d-c);
}