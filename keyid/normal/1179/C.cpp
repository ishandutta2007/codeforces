#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair

const int MAXN=300005,MAXV=1000000,B=1000;

int a[MAXN],b[MAXN],v[MAXV],sum[1005],mn[1005];

void update(int d,int x)
{
	int b=d/1000;
	v[d]+=x;
	sum[b]=0;
	mn[b]=INT_MAX;
	for (int i=b*1000;i<(b+1)*1000;i++)
	{
		sum[b]+=v[i];
		mn[b]=min(mn[b],sum[b]);
	}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v[MAXV-a[i]]--;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		v[MAXV-b[i]]++;
	}
	for (int i=0;i<1000;i++)
	{
		mn[i]=INT_MAX;
		for (int j=i*1000;j<(i+1)*1000;j++)
		{
			sum[i]+=v[j];
			mn[i]=min(mn[i],sum[i]);
		}
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int op,p,x;
		scanf("%d%d%d",&op,&p,&x);
		if (op==1)
		{
			update(MAXV-a[p],1);
			a[p]=x;
			update(MAXV-x,-1);
		}
		else
		{
			update(MAXV-b[p],-1);
			b[p]=x;
			update(MAXV-x,1);
		}
		bool flag=false;
		for (int i=0,s=0;i<1000&&!flag;i++)
		{
			if (mn[i]+s<0)
			{
				int t=0;
				for (int j=i*1000;!flag;j++)
				{
					t+=v[j];
					if (t+s<0)
					{
						flag=true;
						printf("%d\n",MAXV-j);
					}
				}
			}
			s+=sum[i];
		}
		if (!flag)
			puts("-1");
	}
	return 0;
}