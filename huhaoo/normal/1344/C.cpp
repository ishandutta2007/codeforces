/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-05-06 22:55:49
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
const int N=200010;
int n,m,q[N],d[N],l,r,pre[N],suf[N];
std::vector<int> e[N];
int main()
{
	n=read(); m=read();
	fr(i,1,m){ int u=read(),v=read(); e[u].push_back(v); d[v]++; }
	fr(i,1,n) pre[i]=suf[i]=i;
	fr(i,1,n) if(!d[i]) q[++r]=i;
	l=1;
	while(l<=r)
	{
		int u=q[l++];
		for(auto v:e[u]){ d[v]--; if(!d[v]) q[++r]=v; }
	}
	if(r!=n){ printf("-1\n"); return 0; }
	fr(i,1,n) for(auto j:e[q[i]]) pre[j]=std::min(pre[j],pre[q[i]]);
	fd(i,n,1) for(auto j:e[q[i]]) suf[q[i]]=std::min(suf[q[i]],suf[j]);
	int ans=0;
	fr(i,1,n) if(pre[i]==i&&suf[i]==i) ans++;
	printf("%d\n",ans);
	fr(i,1,n) putchar(pre[i]==i&&suf[i]==i?'A':'E');
	putchar(10);
	return 0;
}