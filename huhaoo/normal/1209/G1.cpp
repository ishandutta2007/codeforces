/**************************************************************
	File name: 1209G1.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 9:53:54
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
const int N=200010;
int a[N],n,q,l[N],r[N],m,c,w[N],ans;
struct seg
{
	int l,r,w;
	seg(int L=0,int R=0,int W=0)
	{
		l=L;
		r=R;
		w=W;
	}
}s[N];
int cmp(seg a,seg b)
{
	return a.l<b.l;
}
int main()
{
	n=read();
	m=200000;
	q=read();
	fr(i,1,m)
	{
		l[i]=n+1;
		r[i]=0;
	}
	fr(i,1,n)
	{
		a[i]=read();
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
		w[a[i]]++;
	}
	fr(i,1,m)
		if(r[i])
			s[++c]=seg(l[i],r[i],w[i]);
	sort(s+1,s+n+1,cmp);
	fr(i,1,n)
		if(s[i].r<s[i+1].l||i==n)
			ans+=s[i].w;
		else
		{
			s[i+1].l=min(s[i].l,s[i+1].l);
			s[i+1].r=max(s[i].r,s[i+1].r);
			s[i+1].w=max(s[i].w,s[i+1].w);
		}
	printf("%d\n",n-ans);
	return 0;
}