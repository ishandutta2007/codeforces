/**************************************************************
	File name: 1205A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/18 9:47:55
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
const int N=200010;
int n,a[N];
int main()
{
	n=read();
	if(n&1)
	{
		printf("YES\n");
		fr(i,1,n)
		{
			a[i]=2*i-1;
			a[i+n]=2*i;
		}
		fr(i,1,n)
			if(i&1)
				swap(a[i],a[i+n]);
		fr(i,1,2*n)
			printf("%d%c",a[i],i==2*n?'\n':' ');
	}
	else
		printf("NO\n");
	return 0;
}