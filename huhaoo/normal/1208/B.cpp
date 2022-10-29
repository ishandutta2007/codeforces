/**************************************************************
	File name: 1208B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/25 10:38:13
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
const int N=2010;
int n,m,a[N],A[N],t[N],s,ans;
int main()
{
	n=read();
	ans=n+1;
	fr(i,1,n)
		a[i]=A[i]=read();
	sort(A+1,A+n+1);
	m=unique(A+1,A+n+1)-A-1;
	fr(i,1,n)
		a[i]=lower_bound(A+1,A+m+1,a[i])-A;
	fr(i,1,n)
	{
		s=0;
		fr(i,1,m)
			t[i]=0;
		fr(i,1,n)
			t[a[i]]++;
		fr(i,1,m)
			if(t[i]>1)
				s++;
		if(!s)
		{
			ans=0;
			break;
		}
		fr(j,i,n)
		{
			t[a[j]]--;
			if(t[a[j]]==1)
				s--;
			if(!s)
				ans=min(ans,j-i+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}