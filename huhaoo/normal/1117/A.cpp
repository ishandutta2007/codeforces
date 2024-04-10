/****************************************************************
	File name: 1117A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2/18/2019, 11:33:12 PM
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
#define N 100010
int n,a[N],m,t,ans;
int main()
{
	n=read();
	fr(i,1,n)
	{
		a[i]=read();
		m=max(m,a[i]);
	}
	fr(i,1,n)
		if(a[i]==m)
		{
			t++;
		}
		else
		{
			ans=max(ans,t);
			t=0;
		}
	printf("%d\n",max(ans,t));
	return 0;
}