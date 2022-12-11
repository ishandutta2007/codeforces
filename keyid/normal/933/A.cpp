#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXN=2005;

int a[MAXN],cnt_f[MAXN][2],cnt_b[MAXN][2];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
	}
	for (int i=1;i<=n;i++)
	{
		memcpy(cnt_f[i],cnt_f[i-1],sizeof(cnt_f[i]));
		cnt_f[i][a[i]]++;
	}
	for (int i=n;i>=1;i--)
	{
		memcpy(cnt_b[i],cnt_b[i+1],sizeof(cnt_b[i]));
		cnt_b[i][a[i]]++;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,cnt_f[i][0]+cnt_b[i+1][1]);
	for (int i=1;i<=n;i++)
	{
		int l0=0,l1=0;
		for (int j=i;j<=n;j++)
		{
			if (a[j]==0)
				l0=max(l0,l1)+1;
			else
				l1++;
			ans=max(ans,max(l0,l1)+cnt_f[i-1][0]+cnt_b[j+1][1]);
		}
	}
	printf("%d",ans);
	return 0;
}