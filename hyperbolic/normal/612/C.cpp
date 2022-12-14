#include <stdio.h>
#include <vector>
#include <string.h>

char x[1000010];
std::vector<int> V;
std::vector< std::pair<int,int> > V2;

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='<'||x[i]=='('||x[i]=='{'||x[i]=='[') V.push_back(i);
		else
		{
			if(V.empty())
			{
				printf("Impossible");
				return 0;
			}
			V2.push_back({V.back(),i});
			V.pop_back();
		}
	}
	if(V.size()>0)
	{
		printf("Impossible");
		return 0;
	}
	
	int ans = 0;
	for(int i=0;i<V2.size();i++)
	{
		int s = V2[i].first;
		int t = V2[i].second;
		if(x[s]=='('&&x[t]==')') continue;
		if(x[s]=='{'&&x[t]=='}') continue;
		if(x[s]=='['&&x[t]==']') continue;
		if(x[s]=='<'&&x[t]=='>') continue;
		ans++;
	}
	printf("%d",ans);
}