/***************************************************************
	File name: A.cpp
	Author: huhao
	Create time: Tue 12 May 2020 08:34:46 PM CST
***************************************************************/
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define int long long
const int N=200010;
int n,a,c[N],m[N],M[N],ans=1;
signed main()
{
	n=read();
	fr(i,1,200000) m[i]=M[i]=100000;
	fr(i,1,n)
	{
		a=read();
		for(int j=2;j*j<=a;j++) if(a%j==0)
		{
			int p=0;
			while(a%j==0){ a/=j; p++; }
			c[j]++;
			if(m[j]>p){ M[j]=m[j]; m[j]=p; }
			else if(M[j]>p) M[j]=p;
		}
		if(a!=1)
		{
			c[a]++;
			if(m[a]>1){ M[a]=m[a]; m[a]=1; }
			else if(M[a]>1) M[a]=1;
		}
	}
	fr(i,1,200000) if(c[i]>n-2)
	{
		int p=c[i]==n?M[i]:m[i];
		while(p--) ans=ans*i;
	}
	printf("%I64d\n",ans);
	return 0;
}