#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
char x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		
		int control;
		control = 1;
		for(int i=1;i<=a;i++) if(x[i]!=y[i]) control = 0;
		if(control==1)
		{
			for(int i=1;i<=a;i++) if(x[i]=='0') ans.push_back(std::make_pair(i,i));
			if(ans.size()%2==0)
			{
				ans.push_back(std::make_pair(1,1));
				ans.push_back(std::make_pair(2,a));
			}
			else ans.push_back(std::make_pair(1,a));
			
			printf("YES\n");
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
			continue;
		}
		
		for(int i=1;i<=a;i++) y[i] = '0'+'1'-y[i];
		control = 1;
		for(int i=1;i<=a;i++) if(x[i]!=y[i]) control = 0;
		
		if(control==1)
		{
			for(int i=1;i<=a;i++) if(x[i]=='0') ans.push_back(std::make_pair(i,i));
			if(ans.size()%2==1)
			{
				ans.push_back(std::make_pair(1,1));
				ans.push_back(std::make_pair(2,a));
			}
			else ans.push_back(std::make_pair(1,a));
			
			printf("YES\n");
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
			continue;
		}
		
		printf("NO\n");
	}
}