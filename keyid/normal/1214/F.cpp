#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=200005;

struct Pos
{
	int p,id;
}a[MAXN*2];

int n,sum[MAXN*2][2],ma[MAXN];
LL v[MAXN*2][2];

#define v(i,j) v[i+MAXN][j]

int findx(int x)
{
	while (a[x+1].id<0)
		x=(x+1)%(2*n);
	return x;
}

int findy(int x)
{
	while (a[x+1].id>0)
		x=(x+1)%(2*n);
	return x;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int m;
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].p);
		a[i].id=i;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i+n].p);
		a[i+n].id=-i;
	}
	sort(a+1,a+n*2+1,[](const auto &x,const auto &y) {return x.p<y.p;});
	LL ret=0;
	for (int i=1;i<=n*2;i++)
	{
		for (int j=0;j<2;j++)
			sum[i][j]=sum[i-1][j];
		sum[i][a[i].id>0]++;
		int d=sum[i][a[i].id>0]-sum[i][(a[i].id>0)^1];
		ret+=(d<=0?1:-1)*a[i].p;
		v(d,a[i].id>0)+=a[i].p;
	}
	LL ans=ret;
	int p=0;
	for (int i=1;i<n*2;i++)
	{
		int k=a[i].id>0,d=sum[i][k]-sum[i][k^1];
		ret+=2*(v(d,k)-v(-(d-1),k^1))+m;
		v(d,k)+=m;
		if (ret<ans)
		{
			ans=ret;
			p=i;
		}
	}
	int x=p,y=p;
	for (int i=1;i<=n;i++)
	{
		x=findx(x);
		y=findy(y);
		ma[a[x+1].id]=-a[y+1].id;
		x=(x+1)%(2*n);
		y=(y+1)%(2*n);
	}
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
		printf("%d ",ma[i]);
	return 0;
}