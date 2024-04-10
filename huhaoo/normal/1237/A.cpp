/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-16 22:28:19
****************************************************************/
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
int n,flag;
int main()
{
	n=read();
	fr(i,1,n)
	{
		int a=read();
		if(a%2==0)
			printf("%d\n",a/2);
		else
			printf("%d\n",(a+1)/2-1+(flag^=1));
	}
	return 0;
}