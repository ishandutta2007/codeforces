#include <stdio.h>
#include <vector>

long long int value[50][50];
std::vector< std::pair<int,int> > ans;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i+=2) for(int j=1;j<=a;j++) value[i][j] = (long long int)(1<<((i-1)))*(1<<(j-1));
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			printf("%lld ",value[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		ans.clear();
		long long int c;
		scanf("%lld",&c);
		
		int s = 1, t = 1;
		ans.push_back(std::make_pair(s,t));
		for(int p=1;;p++)
		{
			if(s==a&&t==a) break;
			
			if((c&(1LL<<p))!=0)
			{
				if(s%2==1) t++;
				else s++;
			}
			else
			{
				if(s%2==1) s++;
				else t++;
			}
			ans.push_back(std::make_pair(s,t));
		}
		
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
			fflush(stdout);
		}
	}
}