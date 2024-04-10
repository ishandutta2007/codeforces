#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int a[MAXN],od[MAXN],p[MAXN];
LL s[MAXN],ans[MAXN];

int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}

inline void uni(int u,int v)
{
	if (p[v]==-1) return;
	u=find(u);v=find(v);
	p[u]=v;
	s[v]+=s[u];
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&od[i]);
	for (int i=0;i<=n+1;i++) p[i]=-1;
	for (int i=n-1;i>=0;i--)
	{
		int x=od[i];
		p[x]=x;
		s[x]=a[x];
		uni(x,x+1);
		uni(x,x-1);
		ans[i]=max(ans[i+1],s[find(x)]);
	}
	for (int i=1;i<n;i++) printf("%lld\n",ans[i]);
	printf("0");
	return 0;
}