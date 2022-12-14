#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define MOD 400

std::set<int> S,S1,S2;
std::vector<char> V[100010];
char x[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			int b = strlen(x+1);
			for(int j=1;j<=b;j++) V[i].push_back(x[j]);
		}
		
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==1)
			{
				printf("YES\n");
				goto u;
			}
		}
		
		S.clear();
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==2)
			{
				int s1 = MOD*V[i][0] + V[i][1];
				int s2 = MOD*V[i][1] + V[i][0];
				S.insert(s1);
				if(S.find(s2)!=S.end())
				{
					printf("YES\n");
					goto u;
				}
			}
		}
		
		S.clear();
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==3)
			{
				int s1 = MOD*MOD*V[i][0] + MOD*V[i][1] + V[i][2];
				int s2 = MOD*MOD*V[i][2] + MOD*V[i][1] + V[i][0];
				S.insert(s1);
				if(S.find(s2)!=S.end())
				{
					printf("YES\n");
					goto u;
				}
			}
		}
		
		S1.clear();
		S2.clear();
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()==2)
			{
				int s1 = MOD*V[i][0] + V[i][1];
				int s2 = MOD*V[i][1] + V[i][0];
				S1.insert(s1);
				if(S2.find(s2)!=S2.end())
				{
					printf("YES\n");
					goto u;
				}
			}
			else
			{
				int s1 = MOD*V[i][0] + V[i][1];
				int s2 = MOD*V[i][2] + V[i][1];
				S2.insert(s1);
				if(S1.find(s2)!=S1.end())
				{
					printf("YES\n");
					goto u;
				}
			}
		}
		
		printf("NO\n");
		u:;
	}
}