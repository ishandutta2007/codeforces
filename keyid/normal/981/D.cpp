#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=55;

LL a[MAXN],sum[MAXN];
bool f[MAXN][MAXN];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	LL ans=0;
	for (int i=60;i>=0;i--)
	{
		ans+=1LL<<i;
		memset(f,0,sizeof(f));
		f[0][0]=true;
		for (int j=1;j<=n;j++)
		{
			for (int u=0;u<j;u++)
				if (((sum[j]-sum[u])&ans)==ans)
					for (int l=0;l<k;l++)
						if (f[u][l])
							f[j][l+1]=true;
		}
		if (!f[n][k])
			ans-=1LL<<i;
	}
	printf("%lld",ans);
	return 0;
}