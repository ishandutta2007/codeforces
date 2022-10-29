/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-07-21 22:35:06
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
const int N=100010;
int main()
{
	fr(T,1,read())
	{
		int n;
		static char s[N],t[N];
		static int ans[N],l; l=0;
		scanf("%d%s%s",&n,s+1,t+1);
		fr(i,1,n){ s[i]-=48; t[i]-=48; }
		int p1=1,p2=n,r=0;
		fd(i,n,1)
		{
			if((s[p1]^r)==t[i]) ans[++l]=1;
			ans[++l]=i;
			if(r) p1--;
			else p1++;
			r^=1; std::swap(p1,p2);
		}
		printf("%d ",l);
		fr(i,1,l) printf("%d%c",ans[i],i==l?'\n':' ');
	}
	return 0;
}