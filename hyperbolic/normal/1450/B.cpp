#include <stdio.h>
#include <vector>

std::pair<int,int> P[110];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			P[i]=std::make_pair(c,d);
		}
		
		for(int i=1;i<=a;i++)
		{
			int control = 0;
			for(int j=1;j<=a;j++) if(abs(P[i].first-P[j].first)+abs(P[i].second-P[j].second)>b) control = 1;
			if(control==0)
			{
				printf("1\n");
				goto u;
			}
		}
		printf("-1\n");
		u:;
	}
}