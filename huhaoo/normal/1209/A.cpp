/**************************************************************
	File name: 1209A.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/14 9:06:54
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
const int N=110;
int n,a[N],p[N],ans;
int main()
{
	n=read();
	fr(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1);
	fr(i,1,n)
		if(!p[i])
		{
			ans++;
			fr(j,i,n)
				if(a[j]%a[i]==0)
					p[j]=1;
		}
	printf("%d\n",ans);
	return 0;
}