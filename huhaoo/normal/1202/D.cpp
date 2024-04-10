/**************************************************************
	File name: 1202D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/7 11:36:57
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
const int N=100010;
int n,s[N];
int main()
{
	fr(T,1,read())
	{
		n=read();
		putchar('1');
		int p=1;
		while(p*(p-1)/2<=n)
			p++;
		p--;
		int c=0;
		while(n)
		{
			n-=p*(p-1)/2;
			s[++c]=p;
			while(p*(p-1)/2>n)
				p--;
		}
		s[c+1]=0;
		fd(i,c,1)
		{
			fr(j,s[i+1]+1,s[i])
				putchar('3');
			putchar('7');
		}
		putchar('\n');
	}
	return 0;
}