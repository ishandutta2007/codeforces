/**************************************************************
	File name: maze.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 11/6/2018, 10:06:54 AM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(unsigned long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(unsigned long long i=(a),_end_=(b);i>=_end_;i--)
unsigned long long read()
{
	unsigned long long r=0,t=1,c=getchar();
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
#define N 2510
unsigned long long q,b[N][N],n,m;
void add(unsigned long long p1,unsigned long long p2,unsigned long long v)
{
	for(unsigned long long i=p1;i;i-=i&(-i))for(unsigned long long j=p2;j;j-=j&(-j))
		b[i][j]+=v;
}
unsigned long long query(unsigned long long p1,unsigned long long p2)
{
	unsigned long long ans=0;
	for(unsigned long long i=p1;i<=n;i+=i&(-i))for(unsigned long long j=p2;j<=m;j+=j&(-j))
		ans+=b[i][j];
	return ans;
}
int main()
{
	n=read();m=read();q=read();
	while(q--)
	{
		unsigned long long opt=read();
		if(opt==1)
		{
			unsigned long long x=read(),y=read(),xx=read(),yy=read(),w;
			w=x*y*xx*yy+x*y*xx+y*xx*yy;
			add(xx,yy,w);add(xx,y-1,-w);add(x-1,yy,-w);add(x-1,y-1,w);
		}
		if(opt==2)
		{
			unsigned long long x=read(),y=read(),xx=read(),yy=read(),w;
			w=x*y*xx*yy+x*y*xx+y*xx*yy;
			add(xx,yy,-w);add(xx,y-1,w);add(x-1,yy,w);add(x-1,y-1,-w);
		}
		if(opt==3)
		{
			unsigned long long x=read(),y=read(),xx=read(),yy=read();
			if(query(x,y)==query(xx,yy))printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}