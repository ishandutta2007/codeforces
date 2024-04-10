#include <stdio.h>
#include <set>

std::set<int> S;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++)
		{
			int c = x[i];
			if(S.find(c-b)!=S.end())
			{
				printf("YES\n");
				goto u;
			}
			if(S.find(c+b)!=S.end())
			{
				printf("YES\n");
				goto u;
			}
			S.insert(c);
		}
		printf("NO\n");
		u:;
	}
}