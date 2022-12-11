#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int f[MAXN],ty[MAXN],mx[MAXN];

bool solve()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a<=n&&b<=n)
			return false;
		if (a<=n)
		{
			f[a]=b;
			ty[a]=0;
		}
		else if (b<=n)
		{
			f[b]=a;
			ty[b]=1;
		}
	}
	for (int i=n;i>=1;i--)
		mx[i]=max(f[i],mx[i+1]);
	int qa[2]={0,0},qb[2]={0,0},qat=2*n+1,qbt=2*n+1,ans=0;
	for (int i=1,mn=2*n;i<=n;i++)
	{
		if (f[i]<qat)
		{
			qat=f[i];
			qa[ty[i]]++;
		}
		else if (f[i]<qbt)
		{
			qbt=f[i];
			qb[ty[i]]++;
		}
		else
			return false;
		mn=min(mn,f[i]);
		if (mn>mx[i+1])
		{
			ans+=min(qa[1]+qb[0],qa[0]+qb[1]);
			qa[0]=qa[1]=qb[0]=qb[1]=0;
			qat=qbt=mn=2*n+1;
		}
	}
	printf("%d\n",ans);
	return true;
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	if (!solve())
		puts("-1");
	return 0;
}