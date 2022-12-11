#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=200005,MOD=998244353;

int a[MAXN];
LL sum;

LL work(LL sump,int l,int r)
{
	LL ret=0;
	int head=l+1;
	LL s=sump;
	for (int i=l+1;i<=r;i+=2)
		s+=a[i];
	if ((l+1&1)!=(r&1))
		s+=a[r];
	for (int i=(l+1&1)==(r&1)?r:r-1;i>l;i-=2)
	{
		if (head>i)
		{
			head-=2;
			s+=a[head];
		}
		while (head<=i&&s*2>sum)
		{
			s-=a[head];
			head+=2;
		}
		ret+=(head-l)/2;
		s+=a[i-1];
	}
	head=l+2;
	s=sump;
	for (int i=l+2;i<=r;i+=2)
		s+=a[i];
	if ((l&1)!=(r&1))
		s+=a[r];
	for (int i=(l&1)==(r&1)?r:r-1;i>l;i-=2)
	{
		if (head>i)
		{
			head-=2;
			s+=a[head];
		}
		while (head<=i&&s*2>sum)
		{
			s-=a[head];
			head+=2;
		}
		ret+=(head-l)/2-1;
		s+=a[i-1];
	}
	return ret;
}

int solve()
{
	int n;
	scanf("%d",&n);
	sum=0;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (n==1)
		return 1;
	ans+=work(0,1,n);
	ans+=work(a[1],2,n);
	ans+=work(0,1,n-1);
	ans+=work(a[1],2,n-1);
	LL s=0;
	for (int i=1;i<=n;i++)
	{
		s+=a[i];
		if (s*2>sum)
			ans++;
	}
	return ans%MOD;
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--)
		printf("%d\n",solve());
	return 0;
}