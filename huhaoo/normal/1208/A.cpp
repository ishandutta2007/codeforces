/**************************************************************
	File name: 1208A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/25 10:34:53
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
//01 10 11 01 10
int main()
{
	fr(i,1,read())
	{
		int a=read(),b=read(),n=read();
		printf("%d\n",n%3==0?a:n%3==1?b:a^b);
	}
	return 0;
}