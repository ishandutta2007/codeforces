/****************************************************************
	File name: _B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/28/2018, 11:40:50 PM
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
#define N 1000010
int n,a[N],c[N],s;
int main()
{
	n=read();
	fr(i,1,n)a[i]=read();
	fd(i,n,2)a[i]-=a[i-1];
	fr(i,1,n)
	{
		int f=1;
		fr(j,i+1,n)if(a[j]!=a[j-i])
		{
			f=0;break;
		}
		if(f)c[++s]=i;
	}
	printf("%d\n",s);
	fr(i,1,s)printf("%d%c",c[i],i==s?'\n':' ');
	return 0;
}