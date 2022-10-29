/**************************************************************
	File name: 1209C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 9:17:03
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
int n,t,a[N],p[N],m;
char d[N],l,c[N];
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",d+1);
		fr(i,'0','9')
		{
			m=0;
			int k=0;
			fr(j,1,n)
				if(d[j]<i||(d[j]==i&&k))
					a[j]=1;
				else
				{
					a[j]=2;
					if(d[j]>i)
						k=1;
				}
			fr(j,1,n)
				if(a[j]==1)
					c[++m]=d[j];
			fr(j,1,n)
				if(a[j]==2)
					c[++m]=d[j];
			int flag=1;
			fr(i,2,n)
				if(c[i]<c[i-1])
					flag=0;
			if(flag)
			{
				fr(i,1,n)
					printf("%d",a[i]);
				putchar(10);
				break;
			}
			else if(i=='9')
				printf("-\n");
		}
	}
	return 0;
}