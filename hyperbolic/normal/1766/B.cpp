#include <stdio.h>
#include <set>

std::set<int> S;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int prev = -1;
		S.clear();
		for(int i=1;i<a;i++)
		{
			int val = (x[i]-'a'+1)* 100 + (x[i+1]-'a'+1);
			if(S.find(val)!=S.end())
			{
				printf("YES\n");
				goto u;
			}
			S.insert(prev);
			prev = val;
		}
		printf("NO\n");
		u:;
	}
}