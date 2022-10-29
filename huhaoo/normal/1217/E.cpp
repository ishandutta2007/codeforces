/**************************************************************
	File name: 1217E.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/9/5 10:54:06
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
const int N=800010,M=8,inf=int(1e9)+1;
int n,m1[M+2][N],m2[M+2][N],r[M+5],c,a[200010],p10[M],q;
void build(int j,int k,int l,int r)
{
	m1[j][k]=m2[j][k]=inf;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(j,k<<1,l,mid);
	build(j,k<<1|1,mid+1,r);
}
void update(int j,int k)
{
	if(m1[j][k<<1]<m1[j][k<<1|1])
	{
		m1[j][k]=m1[j][k<<1];
		m2[j][k]=min(m2[j][k<<1],m1[j][k<<1|1]);
	}
	else
	{
		m1[j][k]=m1[j][k<<1|1];
		m2[j][k]=min(m2[j][k<<1|1],m1[j][k<<1]);
	}
}
void modify(int j,int k,int l,int r,int p,int m)
{
	if(l==r)
	{
		m1[j][k]=m;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(j,k<<1,l,mid,p,m);
	else
		modify(j,k<<1|1,mid+1,r,p,m);
	update(j,k);
}
pair<int,int> query(int j,int k,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
		return make_pair(m1[j][k],m2[j][k]);
	if(l>R||r<L)
		return make_pair(inf,inf);
	int mid=(l+r)>>1;
	pair<int,int> s1=query(j,k<<1,l,mid,L,R),s2=query(j,k<<1|1,mid+1,r,L,R);
	if(s1.first<s2.first)
		return make_pair(s1.first,min(s2.first,s1.second));
	else
		return make_pair(s2.first,min(s1.first,s2.second));
}
int main()
{
	srand((unsigned long long)new char);
	n=read();
	q=read();
	fr(i,0,M)
		build(i,1,1,n);
	p10[0]=1;
	fr(i,1,M)
		p10[i]=p10[i-1]*10;
	fr(i,1,n)
	{
		a[i]=read();
		fr(j,0,M)
			if((a[i]/p10[j])%10)
			{
				modify(j,1,1,n,i,a[i]);
			}
	}
//	fr(j,0,M)
//	{
//		printf("%d\n",j);
//		print(r[j]);
//	}
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int p=read(),x=read();
			fr(j,0,M)
				if((a[p]/p10[j])%10)
					modify(j,1,1,n,p,inf);
			a[p]=x;
			fr(j,0,M)
				if((a[p]/p10[j])%10)
					modify(j,1,1,n,p,a[p]);
		}
		else
		{
			int L=read(),R=read(),ans=inf*2,flag=0;
			fr(i,0,M)
			{
				pair<int,int> s=query(i,1,1,n,L,R);
				if(s.second<inf)
				{
					flag=1;
					ans=min(ans,s.first+s.second);
				}
			}
			printf("%d\n",flag?ans:-1);
		}		
	}
	return 0;
}