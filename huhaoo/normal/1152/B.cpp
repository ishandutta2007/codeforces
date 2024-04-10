/**************************************************************
	File name: 1152B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/24 10:42:56
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
int n,l,ans[100];
int main()
{
	n=read();
	fr(i,0,20)
		if((1<<i)<n&&(!(n&(1<<i))))
			l=i+1;
//	fprintf(stderr,"%d\n",l);
	while(l)
	{
		ans[++ans[0]]=l;
		n^=(1<<l)-1;
//		fprintf(stderr,"%d %d %d\n",n,l,n&(1<<(l-1)));
		while(l&&(n&(1<<(l-1))))
			l--;
		if(l)
		{
			ans[0]++;
			n++;
		}
		while(l&&(n&(1<<(l-1))))
			l--;
	}
	printf("%d\n",ans[0]);
	fr(i,1,(ans[0]+1)/2)
		printf("%d%c",ans[i*2-1],i==end_i?'\n':' ');
	return 0;
}