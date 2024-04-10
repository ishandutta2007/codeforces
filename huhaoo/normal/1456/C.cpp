/***************************************************************
	File name: C.cpp
	Author: huhao
	Create time: Sun 29 Nov 2020 03:25:17 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=500010;
int n,k;
i64 a[N],s[N];
i64 b[N],m;
i64 ans;
int main()
{
	n=read(); k=read();
	fr(i,1,n) a[i]=read();
	std::sort(a+1,a+n+1,[&](int x,int y){ return x>y; });
	fr(i,1,n) s[i]=s[i-1]+a[i];
	fr(i,1,n)
		if(s[i-1]>=0) ans+=s[i-1];
		else
		{
			b[++m]=s[i-1];
			fr(j,i,n) b[++m]=a[j];
			break;
		}
//	printf("%lld\n",m);
//	fr(i,1,m) printf("%lld%c",b[i],i==m?'\n':' ');
	memset(s,0,sizeof(s));
	fr(i,1,m)
	{
		if(i>=k+1) s[i]=s[i-k-1];
		ans+=s[i]; s[i]+=b[i];
	}
	printf("%lld\n",ans);
	return 0;
}