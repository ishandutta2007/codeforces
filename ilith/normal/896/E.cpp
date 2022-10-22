#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define R register
#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
float x;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int read()
{
	R int x=0;
	R char a=getchar();
	while (a<'0'||a>'9')  a=getchar();
	while (a>='0'&&a<='9') x=(x<<1)+(x<<3)+(a^48),a=getchar();
	return x;
}
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	while (m--)
	{
		R int opt,l,r,ans=0;
		opt=read(); l=read(); r=read(); x=read();
		if (opt==1)
			for (R int i=l;i<=r;i++) a[i]-=(a[i]>x)?x:0;
		else
		{
			for (R int i=l;i<=r;i++) ans+=!(a[i]-x);
			printf("%d\n",ans);
		}
	}
	return 0;
}