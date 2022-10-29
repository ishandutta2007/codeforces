/**************************************************************
	File name: 1209B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 9:10:26
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
const int N=110;
int a[N],b[N],n;
char c[N];
int main()
{
	n=read();
	scanf("%s",c+1);
	fr(i,1,n)
		c[i]-=48;
	fr(i,1,n)
	{
		b[i]=read();
		a[i]=read();
	}
	int ans=0;
	fr(i,0,100000)
	{
		int t=0;
		fr(j,1,n)
		{
			if(i>=a[j]&&(i-a[j])%b[j]==0)
				c[j]^=1;
			t+=c[j];
		}
		ans=max(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}