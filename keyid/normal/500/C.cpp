#include <cstdio>

const int MAXN=510,MAXM=1010;

struct book
{
	int id,v;
}a[MAXN];

int w[MAXN],b[MAXM],last[MAXN],cnt=0;
bool vis[MAXN];


int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if (!vis[x])
		{
			for (int i=cnt-1;i>=0;i--)
			{
				a[i+1]=a[i];
				ans+=a[i].v;
				last[a[i].id]=i+1;
			}
			vis[x]=true;
			cnt++;
		}
		else
		{
			for (int i=last[x]-1;i>=0;i--)
			{
				a[i+1]=a[i];
				ans+=a[i].v;
				last[a[i].id]=i+1;
			}
		}
		a[0]=(book){x,w[x]};
		last[x]=0;
	}
	printf("%d",ans);
	return 0;
}