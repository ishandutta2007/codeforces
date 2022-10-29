/**************************************************************
	File name: 933A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/20/2018, 11:25:45 AM
**************************************************************/
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
#define N 1000010
int s1[N],s2[N],f[N],g[N],n,a[N],ans;
int main()
{
	n=read();
	fr(i,1,n)a[i]=read();
	fr(i,1,n)s1[i]=s1[i-1]+(a[i]==1),s2[i]=s2[i-1]+(a[i]==2);
	int p=0;
	fr(i,1,n)
	{
		if(s1[i]>=s1[p]+s2[i]-s2[p])p=i;
//		while(s1[p+1]+s2[i]-s2[p+1]>=s1[p]+s2[i]-s2[p]&&p<i)p++;
		f[i]=s1[p]+s2[i]-s2[p];
	}
	p=n;
	fd(i,n,1)
	{
		if(s2[n]-s2[i-1]>=s1[p]-s1[i-1]+s2[n]-s2[p])p=i-1;
//		while(s1[p-1]-s1[i-1]+s2[n]-s2[p-1]>=s1[p]-s1[i-1]+s2[n]-s2[p]&&p>=i)p--;
		g[i]=s1[p]-s1[i-1]+s2[n]-s2[p];
//		printf("%d %d %d %d\n",i,p,s1[p-1]-s1[i-1]+s2[n]-s2[p-1],s1[p]-s1[i-1]+s2[n]-s2[p]);
	}
//	fr(i,1,n)printf("%d%c",f[i],i==n?'\n':' ');
//	fr(i,1,n)printf("%d%c",g[i],i==n?'\n':' ');
	fr(i,0,n)ans=max(ans,f[i]+g[i+1]);
	printf("%d\n",ans);
	return 0;
}