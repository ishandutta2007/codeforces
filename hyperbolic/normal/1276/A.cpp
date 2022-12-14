#include <stdio.h>
#include <vector>
#include <string.h>

char x[150010];
int check[150010];
std::vector< std::pair<char,int> > V;
std::vector<int> ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		ans.clear();
		scanf("%s",x+1);
		
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i+4<=a;i++)
		{
			if(x[i]=='t'&&x[i+1]=='w'&&x[i+2]=='o'&&x[i+3]=='n'&&x[i+4]=='e')
			{
				ans.push_back(i+2);
				check[i+2] = 1;
			}
		}
		for(int i=1;i<=a;i++) if(check[i]==0) V.push_back({x[i],i});
		for(int i=0;i+2<V.size();i++)
		{
			if(V[i].first=='t'&&V[i+1].first=='w'&&V[i+2].first=='o') ans.push_back(V[i+1].second);
			if(V[i].first=='o'&&V[i+1].first=='n'&&V[i+2].first=='e') ans.push_back(V[i+1].second);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		
	}
}