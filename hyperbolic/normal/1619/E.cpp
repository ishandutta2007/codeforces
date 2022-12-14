#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> save;
int x[200010];
int check[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		save.clear();
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int C = 0;
		for(int i=1;i<=a;i++) if(x[i]==0) C++;
		printf("%d ",C);
		
		int p = 1;
		int count = 0;
		int control = 0;
		long long int S = 0;
		for(int i=1;i<=a;i++)
		{
			if(control==1)
			{
				printf("-1 ");
				continue;
			}
			
			while(p<=a&&x[p]<=i-1)
			{
				if(check[x[p]]==0)
				{
					count++;
					check[x[p]] = 1;
				}
				else
				{
					save.push_back(x[p]);
				}
				p++;
			}
			
			if(check[i-1]==0)
			{
				if(save.size()==0)
				{
					control = 1;
					printf("-1 ");
					continue;
				}
				else
				{
					S += (i-1-save.back());
					check[i-1] = 1;
					save.pop_back();
				}
			}
			
			long long int ans = S;
			for(int j=p;j<=a;j++)
			{
				if(x[j]==i) ans++;
				else break;
			}
			printf("%lld ",ans);
		}
		printf("\n");
	}
}