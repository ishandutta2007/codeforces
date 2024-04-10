/****************************************************************
	File name: _D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/29/2018, 12:06:53 AM
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
#define M 20
long long n,m,a[M][N],p[M][N],l[M],c[N];
long long ans;
int main()
{
	n=read();m=read();
	fr(i,1,m)fr(j,1,n)
	{
		a[i][j]=read();
		p[i][a[i][j]]=j;
	}
	l[1]=1;
	while(l[1]<=n)
	{
		fr(i,2,m)l[i]=p[i][a[1][l[1]]];
		long long k=l[1];
		while(1)
		{
			int f=l[1]!=n+1;
			fr(i,2,m)if(a[i][l[i]]!=a[1][l[1]]||l[i]==n+1)f=0;
			if(f)fr(i,1,m)l[i]++;
			else break;
		}
		ans+=(l[1]-k)*(l[1]-k+1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}