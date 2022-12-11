#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=1005;

LL f[MAXN];
int a[MAXN],b[MAXN];

int main()
{
	int n,k1,k2;
	scanf("%d%d%d",&n,&k1,&k2);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int k=k1+k2;
	for (int i=1;i<=n;i++)
		a[i]=abs(a[i]-b[i]);
	priority_queue <int> q;
	for (int i=1;i<=n;i++)
		q.push(a[i]);
	while (k--)
	{
		int v=q.top();q.pop();
		if (v==0)
		{
			k=(k+1)%2;
			printf("%d",k);
			return 0;
		}
		v--;
		q.push(v);
	}
	LL ans=0;
	while (!q.empty())
	{
		ans+=(LL)q.top()*q.top();
		q.pop();
	}
	printf("%lld",ans);
	return 0;
}