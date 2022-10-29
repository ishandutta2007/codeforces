/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Fri 10 Jul 2020 09:39:10 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
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
i64 a[10];
int main()
{
	a[1]=read(); a[2]=read(); a[3]=read();
	printf("First\n1000000000\n"); fflush(stdout);
	int u; a[u=read()]+=1000000000;
	int v=0;
	fr(i,1,3) if(u!=i&&(!v||a[i]>a[v])) v=i;
	i64 k=a[u]-a[v],x=a[v]-a[6-u-v];
	printf("%lld\n",x+k+k); fflush(stdout);
	printf("%lld\n",read()==v?x+k:k); fflush(stdout);
	return 0;
}