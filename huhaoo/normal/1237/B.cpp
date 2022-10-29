/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-16 22:33:32
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
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
int n,a[N],b[N],m,ans;
int main()
{
	n=read();
	fr(i,1,n)
		a[i]=read();
	fr(i,1,n)
		b[read()]=i;
	fr(i,1,n)
	{
		if(b[a[i]]<m)
			ans++;
		m=max(m,b[a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}