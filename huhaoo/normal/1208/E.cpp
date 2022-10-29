/**************************************************************
	File name: 1208E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/25 11:16:59
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
#define i64 long long
const int N=1000010;
i64 n,w,ans[N],a[N],l,s,A[N][22],b[N];
i64 query(i64 l,i64 r)
{
	if(l>r)
		return -1ll<<50;
	int a=b[r-l+1];
	return max(A[l][a],A[r-(1<<a)+1][a]);
}
int main()
{
	n=read();
	w=read();
	fr(i,2,w)
		b[i]=b[i>>1]+1;
	fr(i,1,n)
	{
		l=read();
		fr(j,1,l)
			a[j]=read();
		if(l>w/2)
		{
			fr(j,1,l)
				A[j][0]=a[j];
			fr(k,1,20)
				fr(j,1,l)
					if(j+(1<<k)-1<=l)
						A[j][k]=max(A[j][k-1],A[j+(1<<(k-1))][k-1]);
			fr(j,1,w)
			{
				if(j<=w-l)
					ans[j]+=max(0ll,query(1,j));
				else if(j>l)
					ans[j]+=max(0ll,query(l-(w-j),l));
				else
					ans[j]+=query(l-(w-j),j);
			}
//			fr(j,1,w)
//				printf("%d%c",ans[j],j==w?'\n':' ');
			continue;
		}
		i64 m=0,M=0;
		fr(j,1,l)
			m=max(m,a[j]);
		s+=m;
		fr(j,1,l)
		{
			M=max(M,a[j]);
			ans[j]+=M-m;
		}
		M=0;
		fr(j,1,l)
		{
			M=max(M,a[l-j+1]);
			ans[w-j+1]+=M-m;
		}
	}
	fr(i,1,w)
		printf("%I64d%c",s+ans[i],i==w?'\n':' ');
	return 0;
}