#include <stdio.h>
#include <vector>

int query[110],value[110];
int a;
std::vector< std::pair<int,int> > save;
int doQuery()
{
	printf("? ");
	for(int i=1;i<=a;i++) printf("%d ",query[i]);
	printf("\n");
	fflush(stdout);
	
	int s;
	scanf("%d",&s);
	return s;
}

int main()
{
	scanf("%d",&a);
	
	int last = a;
	int max = a;
	while(last>0)
	{
		for(int i=2;i<=a+1;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(value[j]>0) query[j] = a;
				else query[j] = 1;
			}
			query[last] = i;
			int s = 0;
			if(i<=a) s = doQuery();
			
			if(s>0) save.push_back(std::make_pair(s,(i-1)));
			else
			{
				if(i==2)
				{
					value[last] = max;
					max--, last--;
					while(value[last]>0) last--;
				}
				else
				{
					value[last] = (max+2-i);
					while(!save.empty())
					{
						std::pair<int,int> P = save.back();
						save.pop_back();
						value[P.first] = value[last] + P.second;
					}
					max = (max+1-i);
					last--;
					while(value[last]>0) last--;
				}
				break;
			}
		}
	}
	
	printf("! ");
	for(int i=1;i<=a;i++) printf("%d ",value[i]);
	fflush(stdout);
}