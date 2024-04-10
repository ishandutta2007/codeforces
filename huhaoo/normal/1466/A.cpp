/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-14 23:33:22
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
const int N=1010;
int n,a[N],x[N];
int main()
{
	fr(T,1,read())
	{
		memset(x,0,sizeof(x));
		n=read();
		fr(i,1,n) a[i]=read();
		fr(i,1,n) fr(j,i+1,n) x[a[j]-a[i]]=1;
		int ans=0;
		fr(i,1,1000) ans+=x[i];
		printf("%d\n",ans);
	}
	return 0;
}