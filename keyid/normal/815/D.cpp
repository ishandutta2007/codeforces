#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=500005;

struct card
{
	int v[3];
}c[MAXN];

int mx[3][2][MAXN];
LL sum[MAXN];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,lim[3];
	scanf("%d",&n);
	LL ans=1;
	for (int i=0;i<3;i++)
	{
		scanf("%d",&lim[i]);
		ans*=lim[i];
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&c[i].v[j]);
	for (int i=0;i<3;i++)
	{
		int a=(i+1)%3,b=(i+2)%3;
		for (int j=0;j<n;j++)
		{
			mx[i][0][c[j].v[i]]=max(mx[i][0][c[j].v[i]],c[j].v[a]);
			mx[i][1][c[j].v[i]]=max(mx[i][1][c[j].v[i]],c[j].v[b]);
		}
		for (int j=0;j<2;j++)
			for (int k=lim[i];k>=1;k--)
				mx[i][j][k]=max(mx[i][j][k],mx[i][j][k+1]);
	}
	for (int i=0;i<3;i++)
		for (int j=1;j<=lim[i];j++)
		{
			ans-=(LL)mx[i][0][j]*lim[(i+2)%3];
			ans+=(LL)mx[i][0][j]*mx[i][1][j];
		}
	for (int i=1;i<=lim[1];i++)
		sum[i]=sum[i-1]+mx[1][0][i];
	for (int i=1;i<=lim[0];i++)
	{
		int y=mx[0][0][i],z=mx[0][1][i];
		if (mx[1][0][y]>=z)
			ans-=(LL)y*z;
		else
		{
			int yt=mx[2][1][z];
			ans-=(LL)yt*z;
			ans-=sum[y]-sum[yt];
		}
	}
	printf("%lld",ans);
	return 0;
}