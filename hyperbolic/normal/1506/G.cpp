#include <stdio.h>
#include <vector>
#include <string.h>

std::vector<int> V[30];
std::vector<char> ans;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=a;i>=1;i--) V[x[i]-'a'].push_back(i);
		
		while(1)
		{
			for(int i=25;i>=0;i--)
			{
				if(V[i].size()>0)
				{
					int limit = V[i].back();
					for(int j=i-1;j>=0;j--)
					{
						if(V[j].size()>0 && V[j][0]<limit) goto u;
					}
					ans.push_back('a'+i);
					V[i].clear();
					for(int j=i-1;j>=0;j--) while(!V[j].empty() && V[j].back()<limit) V[j].pop_back();
					goto v;
					u:;
				}
			}
			break;
			v:;
		}
		for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
		printf("\n");
	}
}