/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-02 23:44:27
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
const int N=1000010;
int n,p[N],k,ans;
char s[N];
char query()
{
	scanf("%s",s);
	return *s=='Y';
}
int main()
{
	n=read(); k=read();
	if(k==1)
	{
		fr(i,1,n)
		{
			p[i]=1;
			fr(j,1,i-1)
			{
				printf("? %d\n? %d\n",j,i); fflush(stdout);
				query(); if(query()) p[i]=0;
			}
			ans+=p[i];
		}
		printf("! %d\n",ans);
		return 0;
	}
	fr(i,1,n) p[i]=1;
	fr(i,1,n)
	{
		printf("? %d\n",i); fflush(stdout);
		if(query()) p[i]=0;
	}
	fr(i,2,(n/(k/2))-1) fr(j,1,i) if(i+j<=(n/(k/2)))
	{
		printf("R\n"); fflush(stdout);
		int o=j;
		while(o<=(n/(k/2)))
		{
			fr(l,(o-1)*(k/2)+1,o*(k/2))
			{
				printf("? %d\n",l); fflush(stdout);
				if(query()) p[l]=0;
			}
			o+=i;
		}
	}
	fr(i,1,n) ans+=p[i];
	printf("! %d\n",ans);
	return 0;
}
//