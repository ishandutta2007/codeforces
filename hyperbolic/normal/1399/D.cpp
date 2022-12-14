#include <stdio.h>
#include <map>
#include <set>

std::set<int> S[3];
char x[200010];
int check[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S[0].clear();
		S[1].clear();
		
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int C = 1;
		for(int i=1;i<=a;i++)
		{
			int k = x[i]-'0';
			if(S[k].empty())
			{
				check[i] = C;
				S[1-k].insert(C++);
			}
			else
			{
				int t = *(S[k].begin());
				check[i] = t;
				
				S[k].erase(t);
				S[1-k].insert(t);
			}
		}
		printf("%d\n",C-1);
		for(int i=1;i<=a;i++) printf("%d ",check[i]);
		printf("\n");
	}
}