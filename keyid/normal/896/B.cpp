#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=1005;

int n,a[MAXN];

bool check()
{
	for (int i=1;i<=n;i++)
		if (a[i]==-1)
			return false;
	return true;
}

int main()
{
	int m,c;
	scanf("%d%d%d",&n,&m,&c);
	memset(a,-1,sizeof(a));
	int k=c/2;
	for (int i=0;i<m;i++)
	{
		int p;
		scanf("%d",&p);
		if (p<=k)
		{
			for (int i=1;;i++)
				if (a[i]==-1||a[i]>p)
				{
					a[i]=p;
					printf("%d\n",i);
					break;
				}
		}
		else
		{
			for (int i=n;;i--)
				if (a[i]==-1||a[i]<p)
				{
					a[i]=p;
					printf("%d\n",i);
					break;
				}
		}
		fflush(stdout);
		if (check())
			break;
	}
	return 0;
}