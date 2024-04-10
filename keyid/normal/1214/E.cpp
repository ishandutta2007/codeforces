#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=1000005;

int d[MAXN],v[MAXN*2],pos[MAXN];

bool cmp(int x,int y)
{
	return d[x]>d[y];
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<=n;i++)
		v[i]=i;
	sort(v+1,v+n+1,cmp);
	for (int i=1;i<=n;i++)
		pos[v[i]]=i;
	for (int i=1;i<=n;i++)
		v[i]=v[i]*2-1;
	for (int i=2;i<=n;i++)
		printf("%d %d\n",v[i-1],v[i]);
	int p=n;
	for (int i=1;i<=n;i++)
	{
		if (i+d[v[i]/2+1]>p)
			v[++p]=v[i]+1;
		printf("%d %d\n",v[i]+1,v[i+d[v[i]/2+1]-1]);
	}
	return 0;
}