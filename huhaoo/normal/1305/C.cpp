/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 22:43:41
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
int n,m,a[N],ans;
int main()
{
	n=read(); m=read();
	if(n>m){ printf("0\n"); return 0; }
	fr(i,1,n) a[i]=read();
	ans=1;
	fr(i,1,n) fr(j,i+1,n) ans=ans*(abs(a[i]-a[j])%m)%m;
	printf("%d\n",ans);
	return 0;
}