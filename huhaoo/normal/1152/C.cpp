/**************************************************************
	File name: 1152C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/24 10:53:51
**************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
long long a,b,c,k,ans;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
void run(long long x)
{
	long long d=((a+x-1)/x)*x-a;
	if(lcm(a+d,b+d)<k)
	{
		k=lcm(a+d,b+d);
		ans=d;
	}
	else if(lcm(a+d,b+d)==k)
		ans=min(ans,d);
}
int main()
{
	k=1ll<<60;
	a=read();
	b=read();
	c=abs(a-b);
	fr(i,1,sqrt(c))
		if(c%i==0)
		{
			run(i);
			run(c/i);
		}
	printf("%I64d\n",ans);
	return 0;
}