/***************************************************************
	File name: math.cpp
	Author: huhao
	Create time: Fri 25 Oct 2019 09:09:57 AM CST
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
#define i64 long long
#define int long long
const int N=1000010;
int n,m,a[N],low[N],b[N],c,m1,m2,A[N],x,y;
i64 s[N];
i64 ans;
signed main()
{
	n=read();
	fr(i,1,n)
	{
		a[i]=read();
		A[a[i]]++;
		m=max(m,a[i]);
	}
	fr(i,1,m*2)
		A[i]+=A[i-1];
	fr(i,1,m)
		fr(j,1,m/i)
			s[i]+=j*(A[i*(j+1)-1]-A[i*j-1]);
	sort(a+1,a+n+1);
	fr(i,1,m*2)
	{
		low[i]=low[i-1];
		while(low[i]<n&&a[low[i]+1]<=i)
			low[i]++;
	}
	for(y=2,x=m;y<=m&&x>=1;y++)
	{
		c=0;
		fr(i,1,m/y+1)
		{
			int p=low[i*y-1],mx=2;
			while(p&&a[p]>=(i-1)*y&&mx)
			{
				b[++c]=a[p];
				p--;
				mx--;
			}
		}
		sort(b+1,b+c+1);
		i64 m2=0;
		i64 M1=0,M2=0,sz=0;
		int it1=c,it2=c;
		while(x>1)
		{
			while(it1&&b[it1]>=x)
			{
				sz++;
				if(b[it1]%y>=M1)
				{
					M2=M1;
					M1=b[it1]%y;
				}
				else if(b[it1]%y>=M2)
					M2=b[it1]%y;
				it1--;
			}
			while(it2&&b[it2]>=x*2)
			{
				m2=max(m2,b[it2]%y);
				it2--;
			}
			int S=s[y]-x;
			if(it2!=c&&(((m2/y)-((m2-2*x-y+1)/y))<=S))
				break;
			if(sz>=2&&(M1/y)-((M1-x-y+1)/y)+(M2/y)-((M2-x-y+1)/y)<=S)
				break;
			x--;
		}
		if(x>1)
			ans=max(ans,(i64)x*y);
	}
	printf("%I64d\n",ans);
	return 0;
}