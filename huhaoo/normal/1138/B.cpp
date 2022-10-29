/***************************************************************
	File name: sequence.cpp
	Author: huhao
	Create time: Mon 05 Aug 2019 08:28:13 AM CST
***************************************************************/
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
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=3000010;
int n,a[5][N],s0,s1,s2,s3;
char c1[N],c2[N];
int main()
{
//	freopen("../../down/sequence/2.in","r",stdin);
	n=read();
scanf("%s%s",c1+1,c2+1);
	fr(i,1,n)
	{
		int x=c1[i]-'0',y=c2[i]-'0';
		if(!x&&!y)
		{
			a[0][++s0]=i;
		}
		if(!x&&y)
		{
			a[1][++s1]=i;
		}
		if(x&&!y)
		{
			a[2][++s2]=i;
		}
		if(x&&y)
		{
			a[3][++s3]=i;
		}
	}
	fr(a3,0,s3)
	{
		int a0=n/2+a3-s1-s3;//(2)-(1)
		if(!(a0>=0&&a0<=s0))
			continue;
		int k=n/2-a0-a3;
		if(k>s1+s2||k<0)
			continue;
		int a1=min(k,s1);
		int a2=k-a1;
		fr(i,1,a0)
			printf("%d ",a[0][i]);
		fr(i,1,a1)
			printf("%d ",a[1][i]);
		fr(i,1,a2)
			printf("%d ",a[2][i]);
		fr(i,1,a3)
			printf("%d ",a[3][i]);
		putchar('\n');
		return 0;
	}
	printf("-1\n");
	/*
	 * 0<=a0<=s0 0<=a1<=s1 0<=a2<=s2 0<=a3<=s3
	 * a2+a3=s1-a1+s3-a3	(1)
	 * a0+a1+a2+a3=n/2		(2)
	 * a1+a2+a3=s1+s3-a3	(1)
	 * a0=n/2+a3-s1-s3		(2)-(1)
	 */
	return 0;
}