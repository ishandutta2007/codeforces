/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-01-05 21:43:33
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
int n,a[110],f[110][110][2];
int main()
{
	n=read();
	fr(i,1,n) a[i]=read();
	fr(i,0,n) fr(j,0,n) fr(k,0,1) f[i][j][k]=n+1;
	f[0][0][0]=f[0][0][1]=0;
	fr(i,1,n) fr(j,0,n) fr(k,0,1) fr(o,a[i]==0||a[i]%2==0?0:1,a[i]==0||a[i]%2==1?1:0)
	{
		f[i][j+o][o]=std::min(f[i][j+o][o],f[i-1][j][k]+(k!=o));
	}
	printf("%d\n",std::min(f[n][(n+1)/2][0],f[n][(n+1)/2][1]));
	return 0;
}