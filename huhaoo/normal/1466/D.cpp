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
#define i64 long long
const int N=5000010;
i64 n,a[N],m,d[N],b[N],ans;
int main()
{
	fr(T,1,read())
	{
		n=read(); m=0; ans=0;
		fr(i,1,n) d[i]=0;
		fr(i,1,n) ans+=(a[i]=read());
		fr(i,1,2*(n-1)) d[read()]++;
		fr(i,1,n) fr(j,1,d[i]-1) b[++m]=a[i];
		std::sort(b+1,b+m+1);
		fr(i,1,n-1)
		{
			printf("%I64d%c",ans,i==n-1?'\n':' '); ans+=b[m--];
		}
	}
	return 0;
}