/**************************************************************
	File name: 1208G.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/8/26 12:21:59
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
const int N=1000010;
int p[N],c,n,phi[N],a[N],v[N],m,k;
long long ans;
int main()
{
	n=read();
	k=read();
	if(n==3)
	{
		printf("3\n");
		return 0;
	}
	fr(i,2,n)
	{
		if(!v[i])
		{
			phi[i]=i-1;
			p[++c]=i;
		}
		fr(j,1,c)
			if(i*p[j]<=n)
			{
				v[i*p[j]]=1;
				if(i%p[j]==0)
				{
					phi[i*p[j]]=phi[i]*p[j];
					break;
				}
				else
					phi[i*p[j]]=phi[i]*(p[j]-1);
			}
			else
				break;
	}
	fr(i,3,n)
		a[i-2]=phi[i];
	sort(a+1,a+n-2+1);
//	fr(i,3,n)
//		printf("%d%c",phi[i],i==n?'\n':' ');
	ans=1;
	fr(i,1,k)
		ans+=a[i];
	printf("%I64d\n",ans+(k>1));
	return 0;
}