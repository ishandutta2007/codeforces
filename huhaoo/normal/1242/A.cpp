/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-11-06 23:07:30
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define i64 long long
#define fr(i,a,b) for(i64 i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(i64 i=(a),end_##i=(b);i>=end_##i;i--)
i64 read()
{
	i64 r=0,t=1,c=getchar();
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
i64 n,g=0,m;
int main()
{
	n=read();
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	m=n;
	fr(i,2,sqrt(m))
		if(m%i==0)
		{
			g=__gcd(g,i);
			while(m%i==0)
				m/=i;
			end_i=sqrt(m);
		}
	if(m>1)
		g=__gcd(g,m);
	printf("%I64d\n",g);
	return 0;
}