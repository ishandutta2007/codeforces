#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005;

int d[MAXN];

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n,s;
	scanf("%d%d",&n,&s);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++;
		d[v]++;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (d[i]==1)
			cnt++;
	printf("%.8f",(double)s/cnt*2);
	return 0;
}