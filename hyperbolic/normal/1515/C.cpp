#include <stdio.h>
#include <set>

std::set< std::pair<int,int> > S;
int x[100010],ans[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) ans[i] = i;
		for(int i=1;i<=b;i++) S.insert({x[i],i});
		for(int i=b+1;i<=a;i++)
		{
			std::set< std::pair<int,int> > ::iterator it = S.begin();
			std::pair<int,int> P = (*it);
			S.erase(it);
			ans[i] = P.second;
			S.insert({P.first+x[i],P.second});
		}
		
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		
	}
}