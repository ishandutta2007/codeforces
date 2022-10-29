/**************************************************************
	File name: 1208D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/25 11:06:02
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define int long long
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
int b[N],n,s[N],a[N];
void add(int p,int v)
{
	while(p<=n)
	{
		b[p]+=v;
		p+=p&(-p);
	}
}
int query(int p)
{
	if(p>n)
		return 1ll<<60;
	int v=0;
	while(p)
	{
		v+=b[p];
		p-=p&(-p);
	}
	return v;
}
signed main()
{
	n=read();
	fr(i,1,n)
		s[i]=read();
	fr(i,1,n)
		add(i,i);
	fd(i,n,1)
	{
		int l=1,r=n+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(query(mid-1)>s[i])
				r=mid;
			else
				l=mid+1;
		}
		a[i]=l-1;
		add(a[i],-a[i]);
	}
	fr(i,1,n)
		printf("%I64d%c",a[i],i==n?'\n':' ');
	return 0;
}