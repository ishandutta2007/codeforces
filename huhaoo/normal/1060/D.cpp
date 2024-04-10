/****************************************************************
	File name: CF1060D.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/9/2018, 8:46:53 PM
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
#define N 100010
int n,l[N],r[N];
long long ans;
int main()
{
	n=read();
	fr(i,1,n)l[i]=read()+1,r[i]=read()+1;
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	fr(i,1,n)ans+=max(l[i],r[i]);
	printf("%lld\n",ans);
	return 0;
}