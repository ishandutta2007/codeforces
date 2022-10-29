/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-06-04 22:39:24
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#include<vector>
const int N=500010;
int n,m,a[N],id[N],t[N],p[N];
std::vector<int> e[N];
int main()
{
	n=read(); m=read();
	fr(i,1,m){ int u=read(),v=read(); e[u].push_back(v); e[v].push_back(u); }
	fr(i,1,n){ a[i]=read(); id[i]=i; }
	std::sort(id+1,id+n+1,[&](int x,int y){ return a[x]<a[y]; });
	fr(I,1,n)
	{
		int i=id[I]; p[i]=1;
		for(auto j:e[i]) if(p[j]) t[a[j]]++;
		fr(j,1,a[i]-1) if(!t[j]){ printf("-1\n"); return 0; }
		if(t[a[i]]){ printf("-1\n"); return 0; }
		for(auto j:e[i]) if(p[j]) t[a[j]]--;
	}
	fr(i,1,n) printf("%d%c",id[i],i==n?'\n':' ');
	return 0;
}