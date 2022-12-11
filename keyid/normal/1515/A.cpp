#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

int w[MAXN];

void solve()
{
	int n,x;
	scanf("%d%d",&n,&x);
	bool flag=false;
	int s=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for (int i=1;i<=n;i++)
	{
		s+=w[i];
		if (s==x)
		{
			if (i<n)
			{
				swap(w[i],w[i+1]);
				break;
			}
			puts("NO");
			return;
		}
	}
	puts("YES");
	for (int i=1;i<=n;i++)
		printf("%d ",w[i]);
	puts("");
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}