#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005;

struct edge
{
	int u,v,w;
}e[MAXN];

int dp[MAXN],id[MAXN],t[MAXN];

bool cmp(int a,int b)
{
	return e[a].w<e[b].w;
}

void solve(int l,int r)
{
	if (l==r)
	{
		dp[l]=max(dp[l],1);
		return;
	}
	int m=l+r>>1;
	solve(l,m);
	for (int i=l;i<=r;i++)
		id[i]=i;
	sort(id+l,id+m+1,cmp);
	sort(id+m+1,id+r+1,cmp);
	int head=l;
	for (int i=m+1;i<=r;i++)
	{
		int x=id[i];
		while (head<=m&&e[id[head]].w<e[x].w)
		{
			int y=id[head++];
			t[e[y].v]=max(t[e[y].v],dp[y]);
		}
		dp[x]=max(dp[x],t[e[x].u]+1);
	}
	for (int i=l;i<=m;i++)
		t[e[i].v]=0;
	solve(m+1,r);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	solve(0,m-1);
	int ans=0;
	for (int i=0;i<m;i++)
		ans=max(ans,dp[i]);

	printf("%d",ans);
	return 0;
}