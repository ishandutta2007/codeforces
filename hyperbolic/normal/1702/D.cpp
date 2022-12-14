#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> count[110];
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=26;i++) count[i].clear();
		
		scanf("%s",x+1);
		int a = strlen(x+1);
		int b;
		scanf("%d",&b);
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum += (x[i]-'a'+1);
		if(sum<=b)
		{
			for(int i=1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++) count[x[i]-'a'+1].push_back(i);
			for(int i=26;i>=1;i--)
			{
				while(sum>b&&count[i].size()>0)
				{
					sum -= i;
					x[count[i].back()] = 0;
					count[i].pop_back();
				}
			}
			for(int i=1;i<=a;i++) if(x[i]!=0) printf("%c",x[i]);
			printf("\n");
		}
	}
}