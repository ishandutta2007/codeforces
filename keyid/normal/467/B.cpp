#include <cstdio>

int main()
{
	int num[1000],n,m,k,fedor,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) scanf("%d",&num[i]);
	scanf("%d",&fedor);
	for (int i=0;i<m;i++)
	{
		int x=num[i]^fedor,cnt=0;
		while (x>0)
		{
			if (x%2) cnt++;
			x/=2;
		}
		if (cnt<=k) ans++;
	}
	printf("%d",ans);
	return 0;
}