/**************************************************************
	File name: 1060C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/28/2018, 3:27:09 PM
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
#define N 2010
#define inf (1<<29)
int a[N],b[N],A[N],B[N],x,n,m,ans;
int main()
{
	n=read();m=read();
	fr(i,1,n)a[i]=read()+a[i-1];
	fr(i,1,m)b[i]=read()+b[i-1];
	fr(i,1,n)
	{
		A[i]=inf;
		fr(j,1,n-i+1)A[i]=min(A[i],a[i+j-1]-a[j-1]);
	}
	fr(i,1,m)
	{
		B[i]=inf;
		fr(j,1,m-i+1)B[i]=min(B[i],b[i+j-1]-b[j-1]);
	}
	x=read();
	int j=m;
	fr(i,1,n)
	{
		while(x/A[i]<B[j]&&j)j--;
		ans=max(ans,i*j);
	}
	printf("%d\n",ans);
	return 0;
}