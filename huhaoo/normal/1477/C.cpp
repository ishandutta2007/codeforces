/***************************************************************
	File name: C.cpp
	Author: huhao
	Create time: Fri 29 Jan 2021 09:01:16 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
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
#define pii std::pair<int,int>
const int N=5010;
int n,u;
int p[N];
i64 x[N],y[N];
i64 dis(int u,int v){ return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]); }
int main()
{
	n=read();
	fr(i,1,n){ x[i]=read(); y[i]=read(); }
	u=1;
	fr(i,2,n) if(pii(x[i],y[i])<pii(x[u],y[u])) u=i;
	p[u]=1; printf("%d",u);
	fr(i,2,n)
	{
		int v=0;
		fr(j,1,n) if(!p[j]&&(!v||dis(u,j)>dis(u,v))) v=j;
		p[v]=1; printf(" %d",v); u=v;
	}
	putchar(10);
	return 0;
}