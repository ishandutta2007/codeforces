/***************************************************************
	File name: C.cpp
	Author: huhao
	Create time: Tue 12 May 2020 08:58:07 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define int long long
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
const int N=1010;
const int inf=1ll<<62;
int n,m,q;
char c[N][N];
int d[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
signed main()
{
	n=read(); m=read(); q=read();
	fr(i,1,n) scanf("%s",c[i]+1);
	fr(i,0,n+1) fr(j,0,m+1) d[i][j]=inf;
	fr(i,1,n) fr(j,1,m) fr(k,0,3) if(c[i][j]==c[i+dx[k]][j+dy[k]]) d[i][j]=0;
	fr(i,1,n) fd(j,m-1,1) d[i][j]=std::min(d[i][j],d[i][j+1]+1);
	fr(i,1,n) fr(j,2,m) d[i][j]=std::min(d[i][j],d[i][j-1]+1);
	fd(i,n-1,1) fr(j,1,m) d[i][j]=std::min(d[i][j],d[i+1][j]+1);
	fr(i,2,n) fr(j,1,m) d[i][j]=std::min(d[i][j],d[i-1][j]+1);
	while(q--)
	{
		int x=read(),y=read(),p=read();
		putchar(d[x][y]>=p||(p-d[x][y])%2==0?c[x][y]:c[x][y]^1); putchar(10);
	}
	return 0;
}