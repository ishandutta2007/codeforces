/****************************************************************
	File name: 1117C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2/18/2019, 11:33:14 PM
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
long long x,y,xx,yy,xxx,yyy,n,l,r,sx[N],sy[N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char op[N];
int check(long long q)
{
	xxx=x+(q/n)*sx[n]+sx[q%n];
	yyy=y+(q/n)*sy[n]+sy[q%n];
	if(abs(xx-xxx)+abs(yy-yyy)<=q)
		return 1;
	return 0;
}
int main()
{
	x=read();
	y=read();
	xx=read();
	yy=read();
	n=read();
	scanf("%s",op+1);
	fr(i,1,n)
		if(op[i]=='U')
			op[i]=0;
		else if(op[i]=='D')
			op[i]=1;
		else if(op[i]=='R')
			op[i]=2;
		else
			op[i]=3;
	fr(i,1,n)
	{
		sx[i]=sx[i-1]+dx[op[i]];
		sy[i]=sy[i-1]+dy[op[i]];
	}
	l=0;
	r=(1ll<<60)-1;
	while(l<r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	if(l>=(1ll<<60)-1)
		l=-1;
	printf("%I64d\n",l);
	return 0;
}