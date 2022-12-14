#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
int check[100010][3];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = x[i];
		std::sort(y+1,y+a+1);
		
		for(int i=1;i<=a;i++) check[y[i]][i%2]++;
		
		for(int i=1;i<=a;i++)
		{
			if(check[x[i]][i%2]==0)
			{
				printf("NO\n");
				goto u;
			}
			check[x[i]][i%2]--;
		}
		printf("YES\n");
		u:;
		
		for(int i=1;i<=a;i++) check[x[i]][0] = check[x[i]][1] = 0;
	}
}