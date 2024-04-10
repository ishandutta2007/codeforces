/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 22:28:04
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=110;
int n,a[N],b[N];
int main()
{
	fr(T,1,read())
	{
		n=read();
		fr(i,1,n) a[i]=read();
		fr(i,1,n) b[i]=read();
		std::sort(a+1,a+n+1); std::sort(b+1,b+n+1);
		fr(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
		fr(i,1,n) printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}