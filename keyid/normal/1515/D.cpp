#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int MAXN=200005;

int c1[MAXN],c2[MAXN];

void solve()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	int *cntl=c1,*cntr=c2;
	for (int i=1;i<=n;i++)
		cntl[i]=cntr[i]=0;
	for (int i=0;i<l;i++)
	{
		int c;
		scanf("%d",&c);
		cntl[c]++;
	}
	for (int i=0;i<r;i++)
	{
		int c;
		scanf("%d",&c);
		cntr[c]++;
	}
	for (int i=1;i<=n;i++)
	{
		int m=min(cntl[i],cntr[i]);
		cntl[i]-=m;
		cntr[i]-=m;
	}
	if (l>r)
	{
		swap(l,r);
		swap(cntl,cntr);
	}
	int d=r-n/2,ans=0;
	for (int i=1;i<=n;i++)
		ans+=cntr[i];
	for (int i=1;i<=n;i++)
	{
		int t=min(cntr[i]/2,d);
		d-=t;
		ans-=t;
	}
	printf("%d\n",ans);
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