/**************************************************************
	File name: 1209E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 10:41:25
**************************************************************/
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
const int N=12,M=2010;
int n,m,t,a[M][M],b[M],r[M],c[M],ans;
int cmp(int x,int y)
{
	return b[x]>b[y];
}
void dfs(int t)
{
	if(!t)
	{
		int s=0;
		fr(i,1,n)
			c[i]=0;
		fr(i,1,n)
		{
			fr(j,1,m)
				c[i]=max(c[i],a[i][r[j]]);
			s+=c[i];
		}
		ans=max(ans,s);
		return;
	}
	fr(i,1,n)
	{
		fr(j,1,n)
			a[j-1][r[t]]=a[j][r[t]];
		a[n][r[t]]=a[0][r[t]];
		dfs(t-1);
	}
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		fr(i,1,n)
			fr(j,1,m)
				a[i][j]=read();
		fr(i,1,m)
		{
			b[i]=0;
			fr(j,1,n)
				b[i]=max(b[i],a[j][i]);
			r[i]=i;
		}
		sort(r+1,r+m+1,cmp);
		ans=0;
		dfs(n);
		printf("%d\n",ans);
	}
	return 0;
}