/****************************************************************
	File name: 1117B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2/18/2019, 11:33:13 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
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
long long n,m,m1,m2,k;
int main()
{
	n=read();
	m=read();
	k=read()+1;
	fr(i,1,n)
	{
		long long a=read();
		if(a>m1)
		{
			m2=m1;
			m1=a;
		}
		else if(a>m2)
			m2=a;
	}
	printf("%I64d\n",m1*((m/k)*(k-1)+m%k)+m2*(m/k));
	return 0;
}