/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-29 22:17:53
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
#define i64 long long
int T,n,L=50;
i64 s,S,x,y;
int main()
{
	T=read();
	while(T--)
	{
		n=read(); s=S=x=y=0;
		fr(i,1,n)
		{
			i64 a=read();
			s+=a; S^=a;
		}
		x=((1ll<<L)-2)^S; S^=x; s+=x;
		fr(i,1,L+1) if(((s>>i)&1)!=((S>>(i-1))&1)){ y+=(1ll<<(i-1)); s+=1ll<<i; }
		printf("3\n%I64d %I64d %I64d\n",x,y,y);
	}
	return 0;
}