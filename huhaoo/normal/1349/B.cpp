/***************************************************************
	File name: B.cpp
	Author: huhao
	Create time: Tue 12 May 2020 08:44:14 PM CST
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
const int N=100010;
int T,n,a[N],k,flag,Flag;
int main()
{
	T=read();
	while(T--)
	{
		n=read(); k=read(); flag=Flag=0;
		fr(i,1,n){ a[i]=read(); Flag|=a[i]==k; }
		fr(i,2,n) if(a[i]>=k&&a[i-1]>=k) flag=1;
		fr(i,3,n) if(a[i]>=k&&a[i-2]>=k) flag=1;
		if(Flag&&(n==1||flag)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}