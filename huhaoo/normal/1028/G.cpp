/***************************************************************
	File name: G.cpp
	Author: huhao
	Create time: Fri 05 Mar 2021 08:56:51 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
#define fr(i,a,b) for(i64 i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(i64 i=(a),end_##i=(b);i>=end_##i;i--)
i64 read()
{
	i64 r=0,t=1,c=getchar();
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
#include<map>
std::map<i64,i64> f[10];
#include<vector>
int op=0; i64 val;
int Query(i64 val,std::vector<i64> a)
{
	i64 n=a.size(); if(n>val) return -2;
	fr(i,0,n-1) if(a[i]==val) return -1;
	fr(i,0,n-1) if(val<a[i]) return i;
	return n;
}
int query(std::vector<i64> a)
{
	static int cnt=0; assert((++cnt)<=5);
	assert(a.size()<=10000); if(!op){ printf("%d",(int)a.size());for(auto i:a) printf(" %lld",i);; putchar(10); fflush(stdout); }
	int ans;
	if(op) ans=Query(val,a);
	else ans=read();
//	printf("%d   %lld %lld  %lld\n",ans,val,a[ans-1],val-a[ans-1]);
	assert(ans!=-2); if(ans==-1){ if(op) printf("Accepted.\n"); exit(0); } return ans;
}
i64 solve(int t,i64 l)
{
	i64 st=std::min(l,10000ll);
	if(t==1) return l+st-1;
	i64 p=l-1;
	fr(i,1,st+1) p=solve(t-1,p+1)+1;
//	printf("%d %lld %lld\n",t,l,p-1);
	return f[t][l]=p-1;
}
void calc(i64 l,i64 r)
{
//	fprintf(stderr,"%lld %lld    %lld\n",l,r,r-l);
	r++;
	if(r-l<=10000)
	{
		std::vector<i64> a;
		fr(i,l,r-1) a.push_back(i);
		query(a); assert(0);
	}
	i64 d=r-l;
	std::vector<i64> a;
	fr(i,1,10000) a.push_back(l+(__int128)d*i/10001);
	int u=query(a); a.push_back(r);
	calc(u?a[u-1]+1:l,a[u]-1);
}
void Solve(int t,i64 l)
{
	i64 st=std::min(l,10000ll);
	if(t==1)
	{
		std::vector<i64> a;
		fr(i,0,st-1) a.push_back(l+i);
		query(a); assert(0);
	}
	i64 p=l-1; std::vector<i64> a;
	fr(i,1,st+1)
	{
		if(t-1>1)
		{
			p=f[t-1][p+1]+1;
		}
		else p=p+std::min(p+1,10000ll)+1;
		if(i!=st+1) a.push_back(p);
	}
	int u=query(a);
	Solve(t-1,u?a[u-1]+1:l);
}
int main()
{
	if(op==1) val=read();
//	printf("%lld\n",val);
//	printf("%lld\n",solve(4,1)); return 0;
	if(query({204761410474ll})) calc(204761410475ll,10004205361450474ll);
	else{ solve(4,1); Solve(4,1); }
	return 0;
}