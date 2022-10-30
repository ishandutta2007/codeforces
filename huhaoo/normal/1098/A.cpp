/****************************************************************
	File name: C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/6/2019, 12:24:53 AM
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
#define N 100010
long long f[N],h[N],s[N],a[N],n,fl,ans;
int main()
{
	n=read();
	h[1]=1;
	fr(i,2,n)
	{
		f[i]=read();
		h[i]=h[f[i]]+1;
	}
	fr(i,1,n)
	{
		s[i]=read();
		if(s[i]==-1&&h[i]%2==1)
			fl=1;
		if(s[i]!=-1&&h[i]%2==0)
			fl=1;
	}
	a[1]=s[1];
	fr(i,2,n)
		a[i]=(1<<30)-1;
	fr(i,2,n)
		if(s[i]!=-1)
			a[f[i]]=min(a[f[i]],s[i]-s[f[f[i]]]);
	fr(i,2,n)
		if(s[i]!=-1)
			a[i]=s[i]-a[f[i]]-s[f[f[i]]];
	fr(i,2,n)
		if(s[i]==-1&&a[i]==(1<<30)-1)
			a[i]=0;
	fr(i,1,n)
	{
		ans+=a[i];
		if(a[i]<0)
		{
			// printf("%d\n",i);
			fl=1;
		}
		// printf("%d%c",a[i],i==n?'\n':' ');
	}
	printf("%I64d\n",fl?-1:ans);
	return 0;
}