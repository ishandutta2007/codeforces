/****************************************************************
	File name: CF1059D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/16/2018, 7:48:17 PM
****************************************************************/
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
#define N 100010
#define eps (1e-8)
int x[N],y[N],n,o;
double l=0,r=1e18,mid;
int check(double r)
{
	double L=-1e18,R=1e18;
	fr(i,1,n)
		if(r*2<y[i])return 0;
		else L=max(L,x[i]-sqrt(y[i])*sqrt(r*2-y[i])),R=min(R,x[i]+sqrt(y[i])*sqrt(r*2-y[i]));
	return L<R;
}
int main()
{
	n=read();
	fr(i,1,n)x[i]=read(),y[i]=read();
	o=2;
	fr(i,1,n)if(y[i]<0){o--;break;}
	fr(i,1,n)if(y[i]>0){o--;break;}
	if(!o){printf("-1\n");return 0;}
	fr(i,1,n)y[i]=abs(y[i]);
	fr(i,1,500)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.9lf\n",l);
	return 0;
}