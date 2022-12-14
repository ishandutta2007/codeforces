#include <stdio.h>
#include <vector>
#include <map>

struct str{
	int first;
	int second;
	int index;
}save[1010];

char x[1010];
int check[1010],next[1010];
std::map<int,str> M;
std::vector<str> ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=b+3;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			
			for(int j=1;j+1<=b;j++)
			{
				int t = (x[j]-'0'+1)*26 + (x[j+1]-'0'+1);
				M[t] = {j,j+1,i};
			}
			for(int j=1;j+2<=b;j++)
			{
				int t = (x[j]-'0'+1)*26*26 + (x[j+1]-'0'+1)*26 + (x[j+2]-'0'+1);
				M[t] = {j,j+2,i};
			}
		}
		
		scanf("%s",x+1);
		check[b+1] = 1;
		check[b+2] = check[b+3] = 0;
		for(int j=b;j>=1;j--)
		{
			if(M.find((x[j]-'0'+1)*26 + (x[j+1]-'0'+1))!=M.end() && check[j+2]==1)
			{
				check[j] = 1;
				save[j] = M[(x[j]-'0'+1)*26 + (x[j+1]-'0'+1)];
				next[j] = j+2;
			}
			else if(M.find((x[j]-'0'+1)*26*26 + (x[j+1]-'0'+1)*26 + (x[j+2]-'0'+1))!=M.end() && check[j+3]==1)
			{
				check[j] = 1;
				save[j] = M[(x[j]-'0'+1)*26*26 + (x[j+1]-'0'+1)*26 + (x[j+2]-'0'+1)];
				next[j] = j+3;
			}
			else check[j] = 0;
		}
		
		if(check[1]==0)
		{
			printf("-1\n");
			continue;
		}
		
		ans.clear();
		int p = 1;
		while(p<=b)
		{
			ans.push_back(save[p]);
			p = next[p];
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].index);
	}
}