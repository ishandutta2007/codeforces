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
i64 n,a[N],c[N],f[N],g[N],ans;
int main()
{
	fr(T,1,read())
	{
		n=read(); ans=0;
		fr(i,1,n) a[i]=read();
		fr(i,0,60) c[i]=0;
		fr(i,1,n) fr(j,0,60) if((a[i]>>j)&1) c[j]++;
		fr(i,1,n)
		{
			f[i]=g[i]=0;
			fr(j,0,60)
			{
				i64 J=(1ll<<j)%mod;
				if((a[i]>>j)&1)
				{
					g[i]+=J*n%mod;
					f[i]+=J*c[j]%mod;
				}
				else
				{
					g[i]+=J*c[j]%mod;
				}
			}
			f[i]%=mod; g[i]%=mod;
			ans+=f[i]*g[i]%mod;
		}
		printf("%I64d\n",ans%mod);
	}
	return 0;
}