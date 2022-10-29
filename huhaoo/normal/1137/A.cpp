/**************************************************************
	File name: 1137A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 3/8/2019, 5:09:07 PM
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
#define N 1010
int n,m,a[N][N],b[N],x[N][N],y[N][N],xx[N][N],yy[N][N],c[N],k;
int main()
{
	n=read();
	m=read();
	fr(i,1,n)
		fr(j,1,m)
			a[i][j]=read();
	fr(i,1,n)
	{
		fr(j,1,m)
			b[j]=a[i][j];
		sort(b+1,b+m+1);
		k=0;
		fr(j,1,m)
			if(b[j]!=b[j-1])
				c[++k]=b[j];
		fr(j,1,m)
		{
			x[i][j]=lower_bound(c+1,c+k+1,a[i][j])-c;
			xx[i][j]=k-x[i][j]+1;
		}
	}
	fr(j,1,m)
	{
		fr(i,1,n)
			b[i]=a[i][j];
		sort(b+1,b+n+1);
		k=0;
		fr(i,1,n)
			if(b[i]!=b[i-1])
				c[++k]=b[i];
		fr(i,1,n)
		{
			y[i][j]=lower_bound(c+1,c+k+1,a[i][j])-c;
			yy[i][j]=k-y[i][j]+1;
		}
	}
	fr(i,1,n)
		fr(j,1,m)
			printf("%d%c",max(x[i][j],y[i][j])+max(xx[i][j],yy[i][j])-1,j==m?'\n':' ');
	return 0;
}