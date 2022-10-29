/**************************************************************
	File name: 1149A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/29 10:38:19
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
const int N=400010;
int a,b,n;
int main()
{
	n=read();
	fr(i,1,n)
		if(read()==1)
			a++;
		else
			b++;
	if(b)
	{
		printf("2 ");
		b--;
	}
	if(a)
	{
		printf("1 ");
		a--;
	}
	while(a>=2)
	{
		printf("1 1 ");
		a-=2;
	}
	while(b)
	{
		printf("2 ");
		b--;
	}
	if(a)
		printf("1 ");
	printf("\n");
	return 0;
}