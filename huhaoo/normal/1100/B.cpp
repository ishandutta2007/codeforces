/****************************************************************
	File name: B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/13/2019, 10:45:21 PM
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
#define N 400010
int n,m,a,t[N],s;
int main()
{
	n=read();
	m=read();
	fr(i,1,m)
	{
		a=read();
		if(!t[a])
			s++;
		t[a]++;
		if(s==n)
		{
			s=0;
			putchar('1');
			fr(i,1,n)
			{
				t[i]--;
				if(t[i])
					s++;
			}
		}
		else
			putchar('0');
	}
	putchar('\n');
	return 0;
}