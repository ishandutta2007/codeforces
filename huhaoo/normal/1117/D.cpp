/****************************************************************
	File name: 1117D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2/18/2019, 11:33:15 PM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
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
#define mod 1000000007
#define N 110
long long ans[N][2],k[N][N],d[N][N],n,m;
int main()
{
	m=read();
	n=read();
	fr(i,1,n-1)
		k[i][i+1]=1;
	k[n][1]=1;
	k[n][n]=1;
	fr(i,1,n)
		ans[i][1]=1;
	while(m)
	{
		if(m&1)
		{
			fr(i,1,n)
				d[i][1]=0;
			fr(i,1,n)
				fr(j,1,n)
					d[i][1]=(d[i][1]+k[i][j]*ans[j][1])%mod;
			fr(i,1,n)
				ans[i][1]=d[i][1];
		}
		m>>=1;
		fr(i,1,n)
			fr(j,1,n)
				d[i][j]=0;
		fr(i,1,n)
			fr(j,1,n)
				fr(o,1,n)
					d[i][j]=(d[i][j]+k[i][o]*k[o][j])%mod;
		fr(i,1,n)
			fr(j,1,n)
				k[i][j]=d[i][j];
	}
	printf("%I64d\n",ans[1][1]);
	return 0;
}