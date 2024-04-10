/***************************************************************
	File name: D.cpp
	Author: huhao
	Create time: Tue 16 Mar 2021 04:05:52 PM CST
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
#include<random>
const int N=100010,M=100000000;
namespace grader
{
	int n,m,a[N],b[N];
	void init()
	{
		n=read(); m=read();
		fr(i,1,n) a[i]=read();
		fr(i,1,m) b[i]=read();
		a[0]=b[0]=-4*M; a[n+1]=b[m+1]=4*M;
		std::sort(a+1,a+n+1); std::sort(b+1,b+m+1);
	}
	int query(int x,int y)
	{
//		printf("%d %d\n",x,y);
		assert(-M<=x&&x<=M&&-M<=y&&y<=M);
		int p1=std::lower_bound(a+1,a+n+1,x)-a,p2=std::lower_bound(b+1,b+m+1,y)-b;
		return std::min({a[p1]-x,x-a[p1-1],b[p2]-y,y-b[p2-1]});
	}
}
int op=0; int cnt=0;
int x[N],y[N],n,m;
int query(int x,int y){ if(cnt++==300000){ printf("1 %d %d\n",n,m); exit(0); } printf("0 %d %d\n",x,y); fflush(stdout); int ans=op?grader::query(x,y):read(); if(ans==-1) exit(0); return ans; }
std::mt19937 _rand(123456789);
int rand(int l,int r){ return int(_rand()%(r-l+1))+l; }
int main()
{
	if(op==1) grader::init();
	x[0]=y[0]=-M-1;
	while(1)
	{
		int p=8,d=-1; int X=x[n],Y=y[m];
		while(X+p<=M&&Y+p<=M)
		{
			if((d=query(X+p,Y+p))<p) break;
			p*=8; d=-1;
		}
		p/=8;
		while(X+p<=M&&Y+p<=M)
		{
			if((d=query(X+p,Y+p))<p) break;
			p*=2; d=-1;
		}
		if(d<0) break;
//		printf("%d %d  %d  %d\n",X,Y,p,d);
		if(!d)
		{
			int flag;
			flag=0; fr(i,1,5) if(query(X+p,rand(-M,M))) flag=1; if(!flag) x[++n]=X+p;
			flag=0; fr(i,1,5) if(query(rand(-M,M),Y+p)) flag=1; if(!flag) y[++m]=Y+p;
		}
		else
		{
			if(X+p+d<=M&&!query(X+p+d,Y+p)) x[++n]=X+p+d;
			else y[++m]=Y+p+d;
		}
	}
	if(x[n]<y[m])
	{
		int p=x[n],Y=-M,d=y[1]-Y-1;
		fr(i,2,m) if((y[i]-y[i-1])/2-1>d)
		{
			d=(y[i]-y[i-1])/2-1; Y=(y[i]+y[i-1])/2;
		}
		if(M-y[m]-1>d){ d=M-y[m]-1; Y=M; }
//		printf("%d %d %d\n",d,Y,p);
		int dd,c;
		while(1)
		{
			dd=1; c=-1;
			while(p+dd<=M)
			{
//				printf("%d %d   %d %d\n",Y,p+dd,dd,query(Y,p+dd));
				if((c=query(p+dd,Y))<std::min(d,dd)) break;
				dd=std::min(dd<<1,dd+d); c=-1;
			}
			if(c<0) break;
			x[++n]=(p+=dd+c);
		}
	}
	else
	{
		std::swap(n,m);
		fr(i,0,N-10) std::swap(x[i],y[i]);
		int p=x[n],Y=-M,d=y[1]-Y-1;
		fr(i,2,m) if((y[i]-y[i-1])/2-1>d)
		{
			d=(y[i]-y[i-1])/2-1; Y=(y[i]+y[i-1])/2;
		}
		if(M-y[m]-1>d){ d=M-y[m]-1; Y=M; }
//		printf("%d %d %d\n",d,Y,p);
		int dd,c;
		while(1)
		{
			dd=1; c=-1;
			while(p+dd<=M)
			{
//				printf("%d %d   %d %d\n",Y,p+dd,dd,query(Y,p+dd));
				if((c=query(Y,p+dd))<std::min(d,dd)) break;
				dd=std::min(dd<<1,dd+d); c=-1;
			}
			if(c<0) break;
			x[++n]=(p+=dd+c);
		}
		std::swap(n,m);
		fr(i,0,N-10) std::swap(x[i],y[i]);
	}
	printf("1 %d %d\n",n,m);
	fr(i,1,n) printf("%d%c",x[i],i==n?'\n':' ');
	fr(i,1,m) printf("%d%c",y[i],i==m?'\n':' ');
	if(op) printf("%d\n",cnt);
	return 0;
}