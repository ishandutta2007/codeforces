#include <stdio.h>
#include <vector>
struct str{
	int value1;
	int value2;
	int value3;
	int value4;
};
std::vector<str> ans;

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		if(x[1][1]=='1')
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=b;j>=2;j--)
			{
				if(x[i][j]=='1')
				{
					ans.push_back({i,j-1,i,j});
				}
			}
		}
		
		for(int i=a;i>=2;i--) if(x[i][1]=='1') ans.push_back({i-1,1,i,1});
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d %d\n",ans[i].value1,ans[i].value2,ans[i].value3,ans[i].value4);
	}
}