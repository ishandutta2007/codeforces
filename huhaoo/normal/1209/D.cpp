/**************************************************************
	File name: 1209D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 9:25:14
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
const int N=100010;
int n,k,f[N],w[N],ans;
int getf(int x)
{
	return x==f[x]?x:f[x]=getf(f[x]);
}
int main()
{
	n=read();
	k=read();
	fr(i,1,n)
	{
		f[i]=i;
		w[i]=1;
	}
	fr(i,1,k)
	{
		int u=getf(read()),v=getf(read());
		if(u!=v)
		{
			w[v]+=w[u];
			w[u]=0;
			f[u]=v;
		}
	}
	fr(i,1,n)
		if(i==f[i])
			ans+=w[i]-1;
	printf("%d\n",k-ans);
	return 0;
}