/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-11-06 23:16:38
****************************************************************/
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
#include<vector>
const int N=100010;
int n,m,vis[N],D,s,Ans,ans,flag;
vector<int>t[N];
void dfs(int u,int c)
{
	s++;
	D+=t[u].size()-2;
	if(s*(n-s)-D>m)
		flag=1;
	if(s*(n-s)-D>m||(vis[u]&&vis[u]!=c))
		Ans=0;
	if(!Ans)
		return;
	if(vis[u])
		return;
	vis[u]=c;
	fr(i,0,t[u].size()-2)
		fr(j,t[u][i]+1,t[u][i+1]-1)
		{
			dfs(j,c);
			if(!Ans)
				return;
		}
}
int main()
{
	n=read();
	m=read();
	fr(i,1,m)
	{
		int u=read(),v=read();
		t[u].push_back(v);
		t[v].push_back(u);
	}
	fr(i,1,n)
	{
		t[i].push_back(0);
		t[i].push_back(n+1);
		sort(t[i].begin(),t[i].end());
	}
	fr(i,1,n)
		if(!vis[i])
		{
			s=0;
			D=0;
			Ans=1;
			dfs(i,i);
			ans+=Ans;
		}
	printf("%d\n",ans+flag-1);
	return 0;
}