/****************************************************************
	File name: _E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/29/2018, 12:34:13 AM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
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
#define N 300010
long long n,q,a[N],b[N],r[N],s[N],s1,s2;
long long cmp(long long x,long long y)
{
	return a[x]-b[x]<a[y]-b[y];
}
int main()
{
	n=read();q=read();
	fr(i,1,n)
	{
		a[i]=read();
		b[i]=read();
		s1+=b[i];
		r[i]=i;
	}
	sort(r+1,r+n+1,cmp);
	fr(i,1,n)
	{
		s[r[i]]=s1+(n-2)*b[r[i]]+s2+(n-i)*(a[r[i]]-b[r[i]]);
		s2+=a[r[i]]-b[r[i]];
	}
	fr(i,1,q)
	{
		int u=read(),v=read();
		s[u]-=min(a[u]+b[v],a[v]+b[u]);
		s[v]-=min(a[u]+b[v],a[v]+b[u]);
	}
	fr(i,1,n)printf("%lld%c",s[i],i==n?'\n':' ');
	return 0;
}