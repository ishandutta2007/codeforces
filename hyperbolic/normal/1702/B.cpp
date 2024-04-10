#include <stdio.h>
#include <string.h>
#include <set>

std::set<char> S;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		int ans = 1;
		for(int i=1;i<=a;i++)
		{
			S.insert(x[i]);
			if(S.size()==4)
			{
				S.clear();
				ans++;
				
				S.insert(x[i]);
			}
		}
		printf("%d\n",ans);
	}
}