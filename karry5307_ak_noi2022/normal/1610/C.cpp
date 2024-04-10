#include<cstdio>

using namespace std;

int n;
int a[300000],b[300000];

bool check(int x)
{
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x-cur&&b[i]>=cur-1)cur++;
		if(cur==x+1)break;
	}
	return cur==x+1;
}

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;if(check(mid))l=mid;else r=mid-1;
		}
		printf("%d\n",l);
	}
}