#include <stdio.h>
#include <string.h>
#include <vector>
#define SIZE 320


std::vector<int> V[30];
char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) V[x[i]-'a'].push_back(i);
	
	long long int ans = 0;
	for(int i=0;i<26;i++) ans = ans>V[i].size()?ans:V[i].size();
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			long long int count = 0;
			int p = 0;
			for(int k=0;k<V[i].size();k++)
			{
				while(p<V[j].size())
				{
					if(V[i][k]<V[j][p])
					{
						count += (V[j].size()-p);
						break;
					}
					else p++;
				}
			}
			ans = ans>count?ans:count;
		}
	}
	printf("%lld",ans);
}