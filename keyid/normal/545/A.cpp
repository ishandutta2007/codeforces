#include <cstdio>

const int MAXN=105;

bool bad[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			if (x==1) bad[i]=true;
			else if (x==2) bad[j]=true;
			else if (x==3) bad[i]=bad[j]=true;
		}
	int cnt=0;
	for (int i=1;i<=n;i++) if (!bad[i]) cnt++;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) if (!bad[i]) printf("%d ",i);
	return 0;
}