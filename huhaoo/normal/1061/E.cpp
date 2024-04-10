/**************************************************************
	File name: 1061E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/9/2019, 2:48:50 PM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
namespace run
{
	#define N 2510
	#define eps 1e-8
	int n,r1,r2,begin1[N],begin2[N],next1[N],next2[N],to1[N],to2[N],e1,e2,w[N],x,y,f1[N],f2[N];
//	int id[N];
//	double ans[N];
	double a[N][N];
	#define fo1(i,a) for(int i=begin1[a];i;i=next1[i])
	#define fo2(i,a) for(int i=begin2[a];i;i=next2[i])
	void add1(int u,int v)
	{
		e1++;
		next1[e1]=begin1[u];
		begin1[u]=e1;
		to1[e1]=v;
	}
	void add2(int u,int v)
	{
		e2++;
		next2[e2]=begin2[u];
		begin2[u]=e2;
		to2[e2]=v;
	}
	void pivot(int l,int e)
	{
		double k=a[l][e];
		a[l][e]=1;
		fr(i,0,x)
			a[l][i]/=k;
		fr(i,0,y)
			if(i!=l&&fabs(a[i][e])>eps)
			{
				k=a[i][e];
				a[i][e]=0;
				fr(j,0,x)
					a[i][j]-=a[l][j]*k;
			}
	}
	int init()
	{
		while(1)
		{
			int e=0,l=0;
			fr(i,1,y)
				if(a[i][0]<-eps&&(!l||(rand()&1)))
					l=i;
			if(!l)break;
			fr(i,1,x)
				if(a[l][i]<-eps&&(!e||(rand()&1)))
					e=i;
			if(!e)
			{
				printf("-1\n");
				return 0;
			}
			pivot(l,e);
		}
		return 1;
	}
	int simplex()
	{
		while(1)
		{
			int e=0,l=0;
			double mi=1e15;
			fr(i,1,x)
				if(a[0][i]>eps)
				{
					e=i;
					break;
				}
			if(!e)
				break;
			fr(i,1,y)
				if(a[i][e]>eps&&a[i][0]/a[i][e]<mi)
				{
					mi=a[i][0]/a[i][e];
					l=i;
				}
			if(!l)
			{
				printf("-1\n");
				return 0;
			}
			pivot(l,e);
		}
		return 1;
	}
	void dfs1(int u)
	{
		int v;
		fo1(i,u)
			if((v=to1[i])!=f1[u])
			{
				f1[v]=u;
				dfs1(v);
			}
	}
	void dfs2(int u)
	{
		int v;
		fo2(i,u)
			if((v=to2[i])!=f2[u])
			{
				f2[v]=u;
				dfs2(v);
			}
	}
	void add1(int u)
	{
		a[y-1][u]=1;
		a[y][u]=-1;
		fo1(i,u)
			if(to1[i]!=f1[u])
				add1(to1[i]);
	}
	void add2(int u)
	{
		a[y-1][u]=1;
		a[y][u]=-1;
		fo2(i,u)
			if(to2[i]!=f2[u])
				add2(to2[i]);
	}
	int main()
	{
		n=read();
		r1=read();
		r2=read();
		fr(i,1,n)
			w[i]=read();
		fr(i,1,n-1)
		{
			int u=read(),v=read();
			add1(u,v);
			add1(v,u);
		}
		fr(i,1,n-1)
		{
			int u=read(),v=read();
			add2(u,v);
			add2(v,u);
		}
		dfs1(r1);
		dfs2(r2);
		x=n;
		int q=read();
		fr(i,1,n)
			a[0][i]=w[i];
		while(q--)
		{
			int p=read(),v=read();
			y+=2;
			a[y-1][0]=v;
			a[y][0]=-v;
			add1(p);
		}
		q=read();
		while(q--)
		{
			int p=read(),v=read();
			y+=2;
			a[y-1][0]=v;
			a[y][0]=-v;
			add2(p);
		}
		fr(i,1,n)
		{
			y++;
			a[y][0]=1;
			a[y][i]=1;
		}
		if(init()&&simplex())
		{
			printf("%d\n",int(-a[0][0]+eps));
		}
		return 0;
	}
}
int main()
{
	return run::main();
}