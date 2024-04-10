/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-29 22:02:40
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
int main()
{
	fr(T,1,read())
	{
		int n=read(),k1=read(),k2=read(),flag=0;
		fr(i,1,k1) flag|=read()==n;
		fr(i,1,k2) read();
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}