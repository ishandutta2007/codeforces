/***************************************************************
	File name: D.cpp
	Author: huhao
	Create time: Fri 08 May 2020 08:13:03 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
//             123456789012345678
const i64 inf=4000000000000000000ll,N=100010;
i64 n,a[N],b[N],q;
i64 d(i64 a,i64 x){ return a-3*x*x-3*x-1; }
i64 query(i64 o)
{
	i64 ans=0;
	fr(i,1,n)
	{
		i64 l=1,r=a[i]+1;
		while(l<r)
		{
			i64 mid=(l+r)>>1;
			if(d(a[i],mid-1)>=o) l=mid+1;
			else r=mid;
		}
		ans+=(b[i]=l-1);
	}
	return ans;
}
int main()
{
	n=read(); q=read();
	fr(i,1,n) a[i]=read();
	i64 l=-inf,r=inf;
	while(l<r)
	{
		i64 mid=(l+r)>>1;
		if(query(mid)<=q) r=mid;
		else l=mid+1;
	}
	q-=query(r);
	fr(i,1,n) if(q&&b[i]<a[i]&&d(a[i],b[i])==r-1){ b[i]++; q--; }
	fr(i,1,n) printf("%lld%c",b[i],i==n?'\n':' ');
	return 0;
}