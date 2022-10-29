/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-14 23:33:22
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=5000010,mod=1000000007;
i64 n,m,k,a[N],f[N];
int getf(int u){ return u==f[u]?u:f[u]=getf(f[u]); }
int main()
{
	n=read(); m=read();
	fr(i,1,m) f[i]=i;
	fr(i,1,n)
	{
		int c=read();
		if(c==1)
		{
			int u=getf(read());
			if(u){ a[++k]=i; f[u]=0; }
		}
		else
		{
			int u=getf(read()),v=getf(read());
			if(u!=v)
			{
				if(u) f[u]=v;
				else f[v]=u;
				a[++k]=i;
			}
		}
	}
	i64 ans=1;
	fr(i,1,k) ans=ans*2%mod;
	printf("%I64d %I64d\n",ans,k);
	fr(i,1,k) printf("%I64d%c",a[i],i==k?'\n':' ');
	return 0;
}