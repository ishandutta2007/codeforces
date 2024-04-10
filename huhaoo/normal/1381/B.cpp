/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-07-21 22:56:46
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
const int N=4010;
int n,a[N],b[N],m,f[N][N];
int main()
{
	fr(T,1,read())
	{
		n=read(); m=0;
		fr(i,1,n*2) a[i]=read();
		for(int i=n*2;i;)
		{
			int p=1;
			fr(j,1,i) if(a[j]>a[p]) p=j;
			b[++m]=i-p+1; i=p-1;
		}
		fr(i,0,m) fr(j,0,n) f[i][j]=0;
		f[0][0]=1;
		fr(i,1,m)
		{
			fr(j,0,n) f[i][j]|=f[i-1][j];
			fr(j,b[i],n) f[i][j]|=f[i-1][j-b[i]];
		}
		printf("%s\n",f[m][n]?"YES":"NO");
	}
	return 0;
}