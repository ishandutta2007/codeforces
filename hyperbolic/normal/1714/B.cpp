#include <stdio.h>
#include <set>

int x[200010];
std::set<int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=a;i>=1;i--)
		{
			if(S.find(x[i])!=S.end())
			{
				printf("%d\n",i);
				goto u;
			}
			S.insert(x[i]);
		}
		printf("0\n");
		u:;
	}
}