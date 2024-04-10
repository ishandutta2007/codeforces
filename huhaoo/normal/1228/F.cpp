/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-09-29 21:35:41
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
const int N=1<<20|10;
int n,m,w[N],f[N],s[N],t,ans;
vector<int>e[N];
void dfs(int u)
{
	w[u]=1;
	for(auto v:e[u])
		if(v!=f[u])
		{
			f[v]=u;
			dfs(v);
			w[u]+=w[v];
		}
}
#define error {printf("0\n");exit(0);}
void solve(int u,int d,int op)
{
//	printf("%d %d %d %d\n",u,d,op,w[u]);
	if(!d)
	{
		if(w[u]!=1)
			error;
		return;
	}
	int s[5],t;
	t=0;
	for(auto v:e[u])
		if(v!=f[u])
		{
			s[++t]=v;
			if(t>3)
				error;
		}
	if(!op)
	{
		if(t==2&&w[s[1]]==(1<<d)-1&&w[s[2]]==(1<<d)-1)
		{
			solve(s[1],d-1,0);
			solve(s[2],d-1,0);
			return;
		}
		error;
	}
	if(t==2)
	{
		if(w[s[1]]==(1<<d)-1)
		{
			solve(s[1],d-1,0);
			solve(s[2],d-1,1);
		}
		else if(w[s[2]]==(1<<d)-1)
		{
			solve(s[2],d-1,0);
			solve(s[1],d-1,1);
		}
		else
			error;
		return;
	}
	else if(t==1)
	{
		if(d==1)
		{
			ans=u;
			return;
		}
		error;
	}
	else if(t==3)
	{
		if(w[s[2]]==(1<<d)-1)
			swap(s[1],s[2]);
		if(w[s[3]]==(1<<d)-1)
			swap(s[1],s[3]);
		if(w[s[2]]==w[s[3]])
		{
			ans=u;
			solve(s[1],d-1,0);
			solve(s[2],d-2,0);
			solve(s[3],d-2,0);
			return;
		}
	}
	error;
}
int main()
{
	n=read();
	m=(1<<n)-2;
	fr(i,1,(1<<n)-3)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==2)
	{
		printf("2\n1 2\n");
		return 0;
	}
	dfs(1);
	int k=(1<<(n-2))-1,r=0;
	fr(i,1,m)
	{
		t=0;
		if(f[i])
			s[++t]=m-w[i];
		for(auto j:e[i])
			if(j!=f[i])
				s[++t]=w[j];
		if(t==3&&(s[1]==k)+(s[2]==k)+(s[3]==k)==2)
		{
			if(f[i]&&m-w[i]!=k)
				r=f[i];
			for(auto j:e[i])
				if(j!=f[i]&&w[j]!=k)
				{
					r=j;
					break;
				}
		}
	}
	if(!r)
		error;
	fr(i,1,m)
		f[i]=0;
	dfs(r);
	solve(r,n-1,1);
	if(ans==r)
	{
		printf("2\n%d ",ans);
		for(auto j:e[ans])
			if(w[j]==(1<<(n-1))-1)
				printf("%d\n",j);
		return 0;
	}
	printf("1\n%d\n",ans);
	return 0;
}
/*
3
1 2
2 3
2 4
1 5
1 6
*/