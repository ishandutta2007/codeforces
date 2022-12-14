#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("1\n");
		else if(a==2) printf("-1\n");
		else
		{
			for(int i=1;i<=a*a;i+=2) V.push_back(i);
			for(int i=2;i<=a*a;i+=2) V.push_back(i);
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++)
				{
					printf("%d ",V.back());
					V.pop_back();
				}
				printf("\n");
			}
		}
	}
}