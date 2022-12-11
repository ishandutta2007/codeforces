#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=30000+10;

bool vis[MAXN];
int a[MAXN];
queue <int> q;

int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	q.push(1);
	vis[1]=true;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		int v=u+a[u];
		if (!vis[v])
		{
			vis[v]=true;
			q.push(v);
		}
	}
	printf("%s",vis[t]?"YES":"NO");
	return 0;
}