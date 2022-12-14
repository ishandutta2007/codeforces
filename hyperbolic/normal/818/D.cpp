#include <stdio.h>
#include <set>

std::set< std::pair<int,int> > S;
int x[100010];
int check[1000010],count[1000010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=1000000;i++)
	{
		if(i==b) continue;
		S.insert(std::make_pair(0,i));
	}
	
	int C = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==b)
		{
			C++;
			while(!S.empty())
			{
				std::set< std::pair<int,int> > ::iterator it = S.begin();
				if((it->first)<C)
				{
					check[it->second] = 1;
					S.erase(it);
				}
				else break;
			}
		}
		else
		{
			if(check[x[i]]==0)
			{
				S.erase(std::make_pair(count[x[i]],x[i]));
				count[x[i]]++;
				S.insert(std::make_pair(count[x[i]],x[i]));
			}
		}
	}
	
	if(!S.empty()) printf("%d",S.begin()->second);
	else printf("-1");
}