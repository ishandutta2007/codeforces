/**********************************************************
	File:CF916C.cpp
	Author:huhao
	Email:826538400@qq.com
	Created time:2018-1-29 14:23:17
**********************************************************/
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
#define inf 100000000
int n,m,k;
int prime(int x)
{
	if(x<2)return 0;
	fr(i,2,sqrt(x))
		if(!(x%i))
			return 0;
	return 1;
}
int main()
{
	n=read();m=read();
	k=n*2-2;
	while(!prime(k))k++;
	printf("2 %d\n",k);
	fr(i,3,n)
		printf("1 %d 2\n",i);
	printf("1 2 %d\n",k-2*n+4);
	m-=n-1;
	int i=1;
	while(m)
	{
		i++;
		fr(j,i+1,n)
		{
			printf("%d %d %d\n",i,j,inf);
			m--;
			if(!m)return 0;
		}
	}
	return 0;
}