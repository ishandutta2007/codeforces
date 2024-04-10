/****************************************************************
	File name: A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 1/13/2019, 10:25:32 PM
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
#define N 1010
int a[N],n,k,s0,s1,a0,a1,ans;
int main()
{
	n=read();
	k=read();
	fr(i,1,n)
	{
		a[i]=read();
		if(a[i]==1)
			s1++;
		else
			s0++;
	}
	fr(i,1,n)
	{
		a0=s0;
		a1=s1;
		fr(j,1,n)
			if(i%k==j%k)
			{
				if(a[j]==1)
					a1--;
				else
					a0--;
			}
		ans=max(ans,abs(a1-a0));
	}
	printf("%d\n",ans);
	return 0;
}