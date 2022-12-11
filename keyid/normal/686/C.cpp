#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n,m,c1=1,c2=1,ans;
bool vis[10];

void dfs2(int c,int x)
{
	if (c==0)
	{
		if (x<m) ans++;
		return;
	}
	x*=7;
	for (int i=0;i<7;i++)
		if (!vis[i])
		{
			vis[i]=true;
			dfs2(c-1,x+i);
			vis[i]=false;
		}
}

void dfs(int c,int x)
{
	if (c==0)
	{
		if (x<n)
			dfs2(c2,0);
		return;
	}
	x*=7;
	for (int i=0;i<7;i++)
		if (!vis[i])
		{
			vis[i]=true;
			dfs(c-1,x+i);
			vis[i]=false;
		}
}

int main()
{
	LL t1=7,t2=7;
	scanf("%d%d",&n,&m);
	while (t1<n)
	{
		t1*=7;
		c1++;
	}
	while (t2<m)
	{
		t2*=7;
		c2++;
	}
	if (c1+c2>7)
	{
		printf("0");
		return 0;
	}
	dfs(c1,0);
	printf("%d",ans);
	return 0;
}