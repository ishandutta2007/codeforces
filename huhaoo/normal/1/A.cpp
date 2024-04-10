/**********************************************************
	File:CF1A.cpp
	Author:huhao
	Email:826538400@qq.com
	Created time:2018-1-29 08:38:30
**********************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
	long long a=read(),b=read(),c=read();
	printf("%lld\n",((a+c-1)/c)*((b+c-1)/c));
	return 0;
}