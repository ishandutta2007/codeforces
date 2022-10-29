/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-04-15 22:41:16
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
const int N=300010;
i64 n,a[N],b[N],c[N],A,B,C,t,d[N];
i64 ans;
i64 query(i64 *a,i64 n,i64 v,int &p)
{
	while(p<=n&&a[p]<v) p++;
	if(p>n) return a[n];
	if(p==1) return a[p];
	return a[p]-v<v-a[p-1]?a[p]:a[p-1];
}
int main()
{
	fr(T,1,read())
	{
		//                                      123456789012345678
		A=read(); B=read(); C=read(); n=0; ans=3000000000000000000ll;
		fr(i,1,A) d[++n]=a[i]=read();
		fr(i,1,B) d[++n]=b[i]=read();
		fr(i,1,C) d[++n]=c[i]=read();
		std::sort(a+1,a+A+1); std::sort(b+1,b+B+1); std::sort(c+1,c+C+1); std::sort(d+1,d+n+1);
		int X=1,Y=1,Z=1;
		fr(i,1,n)
		{
			i64 x=query(a,A,d[i],X),y=query(b,B,d[i],Y),z=query(c,C,d[i],Z);
//			printf("%I64d  %I64d %I64d %I64d\n",d[i],x,y,z);
			ans=std::min(ans,(x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z));
		}
		printf("%I64d\n",ans);
	}
	return 0;
}