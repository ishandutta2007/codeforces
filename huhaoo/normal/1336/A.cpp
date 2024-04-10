/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-04-15 22:32:52
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
#define i64 long long
#include<vector>
const int N=200010;
std::vector<int> e[N];
i64 n,w[N],s[N],ans,k;
i64 dfs(int u,int f=0,int d=0)
{
	w[u]=1;
	for(auto v:e[u]) if(v!=f)
	{
		s[u]-=dfs(v,u,d+1); w[u]+=w[v];
	}
	s[u]+=w[u]*d;
	return w[u]*d;
}
int main()
{
	n=read(); k=read();
	fr(i,1,n-1){ int u=read(),v=read(); e[u].push_back(v); e[v].push_back(u); }
	dfs(1);
	std::sort(s+1,s+n+1);
	fr(i,0,k-1) ans+=s[n-i];
	printf("%I64d\n",ans);
	return 0;
}