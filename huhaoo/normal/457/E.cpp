/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Wed 17 Mar 2021 04:12:17 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
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
#define pii std::pair<i64,int>
const int N=200010;
int n,f[N],q;
i64 w[N];
pii mi[N],Mi[N],mx[N],Mx[N];
int getf(int u)
{
	if(u==f[u]) return u;
	int F=getf(f[u]);
	w[u]+=w[f[u]]; return f[u]=F;
}
int merge(int u,int v,int d)
{
	int x=getf(u),y=getf(v);
	if(x==y) return w[u]-w[v]==d;
	f[x]=y; w[x]=d-w[u]+w[v];
	if(mi[x].first+w[x]<=mi[y].first){ Mi[y]=mi[y]; mi[y]={mi[x].first+w[x],mi[x].second}; }
	else if(mi[x].first+w[x]<=Mi[y].first){ Mi[y]={mi[x].first+w[x],mi[x].second}; }
	if(Mi[x].second&&Mi[x].first+w[x]<=Mi[y].first){ Mi[y]={Mi[x].first+w[x],Mi[x].second}; }
	if(mx[x].first+w[x]>=mx[y].first){ Mx[y]=mx[y]; mx[y]={mx[x].first+w[x],mx[x].second}; }
	else if(mx[x].first+w[x]>=Mx[y].first){ Mx[y]={mx[x].first+w[x],mx[x].second}; }
	if(Mx[x].second&&Mx[x].first+w[x]>=Mx[y].first){ Mx[y]={Mx[x].first+w[x],Mx[x].second}; }
	return 1;
}
i64 Div(i64 a,i64 b){ return (a+a+b)/(b+b); }
i64 Mxd;
int main()
{
	n=read(); q=read();
	fr(i,1,n){ f[i]=i; mi[i]=mx[i]={0,i}; }
	fr(i,1,q)
	{
		int u=read(),v=read(),w=read(),b=read(),flag=1;
		if(!merge(u,v,w*b)) flag=0;
		int x=getf(u);
//		fr(j,1,n) getf(j);
//		fr(j,1,n) printf(" %lld%c",::w[j],j==n?'\n':' ');
//		fr(j,1,n) printf(" %d%c",f[j],j==n?'\n':' ');
//		printf("%lld %d  %lld %d\n",mx[x].first,mx[x].second,Mx[x].first,Mx[x].second);
//		printf("%lld %d  %lld %d\n",mi[x].first,mi[x].second,Mi[x].first,Mi[x].second);
		if(getf(1)==x&&(mx[x].second!=1||(mx[x].first==Mx[x].first&&Mx[x].second))) flag=0;
		if(getf(n)==x&&(mi[x].second!=n||(mi[x].first==Mi[x].first&&Mi[x].second))) flag=0;
		if(getf(1)!=x&&getf(n)!=x) Mxd=std::max(Mxd,mx[x].first-mi[x].first);
//		printf("%lld  %lld\n",Mxd,::w[1]-::w[n]);
		if(getf(1)==getf(n)&&::w[1]-::w[n]<=Mxd) flag=0;
		if(!flag){ printf("BAD %d\n",i); return 0; }
	}
	if(getf(1)==getf(n))
	{
		printf("%lld\n",w[1]-w[n]);
		return 0;
	}
	else printf("UNKNOWN\n");
	return 0;
}