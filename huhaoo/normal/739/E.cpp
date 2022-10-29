/***************************************************************
	File name: 739E.cpp
	Author: huhao
	Create time: Wed 25 Sep 2019 06:48:01 PM CST
***************************************************************/
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=2010;
const double eps=1e-8;
int n,a,b,A,B;
double p[N],u[N],l,r,m,L,R,M,ans,Ans;
void Calc()
{
	A=0;
	B=0;
	ans=0;
	fr(i,1,n)
	{
		double c0=0,c1=p[i]-m,c2=u[i]-M,c3=1-(1-p[i])*(1-u[i])-m-M;
		if(c3>c0&&c3>c1&&c3>c2)
		{
			A++;
			B++;
			ans+=c3;
		}
		else if(c2>c0&&c2>c1)
		{
			B++;
			ans+=c2;
		}
		else if(c1>c0)
		{
			A++;
			ans+=c1;
		}
	}
}
void calc()
{
	L=0;
	R=u[0];
	while(R-L>eps)
	{
		M=(R+L)/2;
		Calc();
		if(B>=b)
			L=M;
		else
			R=M;
	}
	M=L;
	Calc();
}
int main()
{
	n=read();
	a=read();
	b=read();
	fr(i,1,n)
	{
		scanf("%lf",&p[i]);
		p[0]=max(p[0],p[i]+eps);
	}
	fr(i,1,n)
	{
		scanf("%lf",&u[i]);
		u[0]=max(u[0],u[i]+eps);
	}
	l=0;
	r=p[0];
	while(r-l>eps)
	{
		m=(r+l)/2;
		calc();
		if(A>=a)
			l=m;
		else
			r=m;
	}
	m=l;
	calc();
	printf("%.5lf\n",ans+m*a+M*b);
	return 0;
}