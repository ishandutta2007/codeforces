/****************************************************************
	File name: C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/13/2019, 10:53:49 PM
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
double n,r;
int main()
{
	n=1.*read();
	r=1.*read();
	printf("%.10lf\n",r*sin(acos(-1.)/n)/(1-sin(acos(-1.)/n)));
	return 0;
}
//R=rsin(pi/n)/(1-sin(pi/n))