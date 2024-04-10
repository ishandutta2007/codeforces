/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-03 22:52:12
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
const int N=1010;
int q[N],l,r,n,d[N];
std::vector<int> e[N];
int main()
{
	n=read();
	fr(i,1,n-1){ int u=read(),v=read(); e[u].push_back(v); e[v].push_back(u); d[u]++; d[v]++; }
	fr(i,1,n) if(d[i]==1) q[++r]=i;
	l=1;
	fr(i,1,n/2)
	{
		int u=q[l++],v=q[l++];
		printf("? %d %d\n",u,v); fflush(stdout);
		int k=read();
		if(k==u){ printf("! %d\n",u); return 0; }
		if(k==v){ printf("! %d\n",v); return 0; }
		for(auto j:e[u]){ d[j]--; if(d[j]==1) q[++r]=j; }
		for(auto j:e[v]){ d[j]--; if(d[j]==1) q[++r]=j; }
	}
	printf("! %d\n",q[r]);
	return 0;
}