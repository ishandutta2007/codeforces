/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-29 22:09:16
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
int n,a[1000010],T,ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read(); ans=0;
		fr(i,1,n) a[i]=read();
		fr(i,1,n-1) if(abs(a[i]-a[i+1])>=2) ans=i;
		if(ans) printf("YES\n%d %d\n",ans,ans+1);
		else printf("NO\n");
	}
	return 0;
}