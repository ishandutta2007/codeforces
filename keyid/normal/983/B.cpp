#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=5005;

int a[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		f[i][i]=a[i];
	for (int k=1;k<n;k++)
	{
		int b;
		for (int j=20;j>=0;j--)
			if (k>>j&1)
			{
				b=j;
				break;
			}
		for (int i=1;i+k<=n;i++)
			f[i][i+k]=f[i][i+k-(1<<b)]^f[i+(1<<b)][i+k];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i-1;j>=1;j--)
			f[j][i]=max(f[j][i],f[j+1][i]);
		for (int j=1;j<=i;j++)
			f[j][i]=max(f[j][i],f[j][i-1]);
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
	return 0;
}