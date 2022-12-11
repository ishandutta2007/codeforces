#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=200005;

vector <int> G[MAXN];
int a[MAXN];
bool vis[MAXN];
queue <int> q;

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	int head=0;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if (a[0]!=1)
	{
		printf("No");
		return 0;
	}
	head=1;
	vis[1]=true;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		int k=G[u].size();
		if (u!=1)
			k--;
		for (int i=head;i<head+k;i++)
			if (!binary_search(G[u].begin(),G[u].end(),a[i]))
			{
				printf("No");
				return 0;
			}
		for (int i=head;i<head+k;i++)
		{
			vis[a[i]]=true;
			q.push(a[i]);
		}
		head+=k;
	}
	printf("Yes");
	return 0;
}