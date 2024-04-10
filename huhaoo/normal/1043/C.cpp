/****************************************************************
	File name: _C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 10/28/2018, 11:50:12 PM
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
char s[N];
int n,a[N],p[N],m;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	fr(i,1,n)if(s[i]=='a')a[++m]=i;
	fr(i,1,m)p[a[i]]^=1,p[a[i]-1]^=1;
	if(m)p[a[1]-1]^=1;
	fr(i,1,n)printf("%d%c",p[i],i==n?'\n':' ');
	return 0;
}