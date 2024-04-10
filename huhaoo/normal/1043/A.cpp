/****************************************************************
	File name: 1043A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/28/2018, 11:35:28 PM
****************************************************************/
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
#define N 110
int n,s,m;
int main()
{
	n=read();
	fr(i,1,n)
	{
		int a=read();
		s+=a;
		m=max(m,a);
	}
	printf("%d\n",max(m,(2*s+n)/n));
	return 0;
}