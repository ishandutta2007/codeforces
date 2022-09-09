#include<cstdio>
#include<algorithm>

using namespace std;

int n,q;
long long a[200000];

struct ST
{
	long long minn[200000][20],maxn[200000][20];int lg[200000];
	void init()
	{
		lg[0]=-1;
		for(int i=1;i<=n;i++)minn[i][0]=maxn[i][0]=a[i],lg[i]=lg[i>>1]+1;
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)
			{
				minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
				maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			}
		}
	}
	long long query_minn(int l,int r)
	{
		int len=lg[r-l+1];return min(minn[l][len],minn[r-(1<<len)+1][len]);
	}
	long long query_maxn(int l,int r)
	{
		int len=lg[r-l+1];return max(maxn[l][len],maxn[r-(1<<len)+1][len]);
	}
}S;

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1,x=0;i<=n;i++){scanf("%d",&x);a[i]-=x;}
	for(int i=2;i<=n;i++)a[i]+=a[i-1];S.init();
	while(q--)
	{
		int l=0,r=0;scanf("%d%d",&l,&r);
		if(a[l-1]!=a[r]){puts("-1");continue;}
		if(S.query_maxn(l,r)>a[r]){puts("-1");continue;}
		printf("%lld\n",a[r]-S.query_minn(l,r));
	}
}