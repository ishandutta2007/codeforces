/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Wed 27 Nov 2019 01:54:00 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=1010;
int n,a[N],p[N],rk[N];
int main()
{
	n=read();
	fr(i,1,n){ a[i]=read()-1; p[i]=i; }
	sort(p+1,p+n+1,[&](int x,int y){ return a[x]>a[y];} );
	fr(i,1,n) rk[p[i]]=i;
	printf("%d\n",n+1);
	fr(i,1,n+1)
	{
		fr(j,1,n) printf("%d",i<rk[j]?i<=a[j]:i==rk[j]+1?1:i!=rk[j]&&i-2<=a[j]);
		putchar(10);
	}
	return 0;
}