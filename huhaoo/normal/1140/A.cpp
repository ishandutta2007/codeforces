/****************************************************************
	File name: 1040A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 3/22/2019, 11:09:31 PM
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
#define N 10010
int n,a[N],m,ans;
int main()
{
	n=read();
	fr(i,1,n)
		a[i]=read();
	int j=0;
	fr(i,1,n)
	{
		m=a[++j];
		while(j<m&&j<=n)
			m=max(m,a[++j]);
		i=j;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}