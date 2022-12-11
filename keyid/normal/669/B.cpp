#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

char s[MAXN];
int d[MAXN];
bool vis[MAXN];
queue <int> q;

int main()
{
	int n;
	scanf("%d%s",&n,s);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
		if (s[i]=='<') d[i]=-d[i];
	}
	q.push(0);
	vis[0]=true;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		u+=d[u];
		if (u<0||u>=n)
		{
			printf("FINITE");
			return 0;
		}
		if (!vis[u])
		{
			vis[u]=true;
			q.push(u);
		}
	}
	printf("INFINITE");
	return 0;
}