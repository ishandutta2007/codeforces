/***************************************************************
	File name: 1178F.cpp
	Author: huhao
	Create time: Wed 16 Oct 2019 08:45:03 PM CST
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
const int N=510,M=1000010,mod=998244353;
i64 n,m,f[N][N],a[M],nex[M],lst[N],b[N],k,vis[N][N];
i64 dfs2(i64 l,i64 r)
{
	if(l>r)
		return 1;
	if(vis[l][r])
		return f[l][r];
	vis[l][r]=1;
	i64& ans=f[l][r];
	ans=0;
	i64 p=l;
	fr(i,l+1,r)
		if(b[i]<b[p])
			p=i;
	i64 ans1=0,ans2=0;
	fr(i,l,p)
		ans1=(ans1+dfs2(l,i-1)*dfs2(i,p-1))%mod;
	fr(i,p,r)
		ans2=(ans2+dfs2(p+1,i)*dfs2(i+1,r))%mod;
	return ans=ans1*ans2%mod;
}
i64 dfs1(i64 l,i64 r,i64 mx)
{
	if(l>r)
		return 1;
	int p=l;
	i64 ans=1;
	while(p<=r)
	{
		if(a[p]<mx)
			return 0;
		while(nex[p])
		{
			if(nex[p]>r)
				return 0;
			ans=ans*dfs1(p+1,nex[p]-1,a[p])%mod;
			p=nex[p];
		}
		p++;
	}
	p=l;
	k=0;
	while(p<=r)
	{
		b[++k]=a[p];
		p=lst[a[p]]+1;
	}
	fr(i,1,k)
		fr(j,1,k)
			vis[i][j]=0;
	return ans*dfs2(1,k);
}
int main()
{
	n=read();
	m=read();
	fr(i,1,m)
	{
		a[i]=read();
		nex[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	printf("%d\n",(int)dfs1(1,m,0));
	return 0;
}