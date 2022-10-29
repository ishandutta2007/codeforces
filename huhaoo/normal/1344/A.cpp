/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-05-06 22:33:48
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
int T;
int n,p[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(); int ans=1;
		fr(i,0,n-1) p[i]=0;
		fr(i,0,n-1) p[(i+read()%n+n)%n]=1;
		fr(i,0,n-1) ans&=p[i];
		printf("%s\n",ans?"Yes":"No");
	}
	return 0;
}