/****************************************************************
	File name: 1141F.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 3/19/2019, 11:17:00 PM
****************************************************************/
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
#define N 1510
int n,a[N],s[N],t,ans,al,ar;
struct line
{
	int l,r,s;
}l[N*N];
bool cmp(line a,line b)
{
	return a.s==b.s?a.r<b.r:a.s<b.s;
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	fr(i,1,n)
		fr(j,i,n)
		{
			t++;
			l[t].l=i;
			l[t].r=j;
			l[t].s=s[j]-s[i-1];
		}
	sort(l+1,l+t+1,cmp);
	for(int i=1,j=1;i<=t;)
	{
		while(l[j].s==l[i].s&&j<=t)
			j++;
		int r=0,k=0;
//		printf("%d\n",l[i].s);
//		fr(o,i,j-1)
//			printf("%d %d\n",l[o].l,l[o].r);
		fr(o,i,j-1)
			if(l[o].l>r)
			{
				r=l[o].r;
				k++;
			}
		if(k>ans)
		{
			ans=k;
			al=i;
			ar=j-1;
		}
		i=j;
	}
	printf("%d\n",ans);
	int r=0,k=0;
	fr(o,al,ar)
		if(l[o].l>r)
		{
			r=l[o].r;
			printf("%d %d\n",l[o].l,l[o].r);
		}
	return 0;
}