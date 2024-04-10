/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 23:04:05
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
i64 n,m;
int main()
{
	n=read(); m=read();
//	freopen("E.out","w",stdout);
	if(n==1){ printf("%d\n",m==0?1:-1); return 0; }
	fr(i,1,n-1)
	{
		i64 s=0;
		fr(j,1,i) s+=std::max(i-j-j,0);
//		fr(j,1,i) printf("%d %d %I64d\n",i,j,s+(i-j+1)/2);
		fr(j,1,i) if(s+(i-j+1)/2==m)
		{
			fr(k,1,i) printf("%d ",k);
			printf("%d ",i+j);
			fd(j,n-i-2,0) printf("%d ",1000000000-30000*j);
			putchar(10);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}