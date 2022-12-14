#include <stdio.h>
#include <set>
#include <string.h>

std::set<long long int> S;
char x[100010][11];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++)
		{
			int b = strlen(x[i]+1);
			long long int s = 0;
			for(int j=1;j<=b;j++) s*=27, s+=(x[i][j]-'a'+1);
			S.insert(s);
		}
		
		for(int i=1;i<=a;i++)
		{
			int b = strlen(x[i]+1);
			for(int j=1;j<=b;j++)
			{
				long long int s1 = 0, s2 = 0;
				for(int k=1;k<=j;k++) s1*=27, s1+=(x[i][k]-'a'+1);
				for(int k=j+1;k<=b;k++) s2*=27, s2+=(x[i][k]-'a'+1);
				if(S.find(s1)!=S.end()&&S.find(s2)!=S.end())
				{
					printf("1");
					goto u;
				}
			}
			printf("0");
			u:;
		}
		printf("\n");
	}
}