#include <stdio.h>

int x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) x[i] ^= x[i-1];
		if(x[a]==0) printf("YES\n");
		else
		{
			int sum = 0;
			int count = 0;
			for(int i=1;i<=a;i++)
			{
				if((x[i]^sum)==x[a])
				{
					count++;
					sum = x[i];
				}
			}
			if(count>=2) printf("YES\n");
			else printf("NO\n");
		}
	}
}