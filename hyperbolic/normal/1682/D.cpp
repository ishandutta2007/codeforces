#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
std::vector<int> ans2;

char x[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		ans2.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int C = 0;
		for(int i=1;i<=a;i++) C += (x[i]-'0');
		if(C==0||C%2==1)
		{
			printf("NO\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) x[i+a] = x[i];
		int start;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='1')
			{
				start = i;
				break;
			}
		}
		
		int start2 = start;
		while(start<a+start2)
		{
			int end = start;
			for(int j=start+1;j<a+start;j++)
			{
				if(x[j]=='0') end = j;
				else break;
			}
			for(int j=start;j+1<=end;j++) ans.push_back(std::make_pair(j,j+1));
			ans2.push_back(end);
			start = end+1;
		}
		
		for(int i=1;i<ans2.size();i++) ans.push_back(std::make_pair(ans2[0],ans2[i]));
		
		printf("YES\n");
		for(int i=0;i<ans.size();i++) printf("%d %d\n",(ans[i].first-1)%a+1,(ans[i].second-1)%a+1);
		
	}
}