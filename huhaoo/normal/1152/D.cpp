/**************************************************************
	File name: 1152D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/24 11:16:59
**************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=1010,mod=1000000007;
int f[N][N][2],n;
int main()
{
	n=read();
	fr(i,1,n)
	{
		f[0][i][0]=i/2;
		f[0][i][1]=(i+1)/2;
	}
	fr(i,1,n)
	{
		f[i][i][0]=f[i-1][i][1];
		f[i][i][1]=(1+f[i-1][i][0])%mod;
		fr(j,i+1,n)
		{
			//case 0
			f[i][j][0]=(f[i-1][j][1]+f[i][j-1][1])%mod;
			//case 1
			f[i][j][1]=(1+f[i-1][j][0]+f[i][j-1][1])%mod;
		}
	}
	printf("%d\n",f[n][n][1]);
	return 0;
}