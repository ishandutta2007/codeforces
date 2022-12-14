#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<char> V[50010];
char x[50010];
int s1[50010],s2[50010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear(),V[i].push_back('?');
		for(int i=0;i<=a;i++) s1[i] = 0;
		for(int j=0;j<=b;j++) s2[j] = 0;
		
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			for(int j=1;j<=b;j++) V[i].push_back(x[j]);
		}
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) s1[i] += (V[i][j]=='*'?1:0);
		for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) s2[j] += (V[i][j]=='*'?1:0);
		
		int ans = a+b-1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				int t;
				if(V[i][j]=='*') t = (a+b-1) - (s1[i]+s2[j]-1);
				else t = (a+b-1) - (s1[i]+s2[j]);
				
				ans = ans<t?ans:t;
			}
		}
		printf("%d\n",ans);
	}
}