#include <stdio.h>
#include <string.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
std::pair<int,int> next[110];
int len[110];
char x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) next[i] = std::make_pair(0,0);
		
		int b;
		scanf("%d",&b);
		for(int k=1;k<=b;k++)
		{
			scanf("%s",y+1);
			int c = strlen(y+1);
			len[k] = c;
			for(int i=1;i+c-1<=a;i++)
			{
				int control = 0;
				for(int j=1;j<=c;j++) if(y[j]!=x[i+j-1]) control = 1;
				if(control==0) next[i] = next[i]>std::make_pair(i+c,k)?next[i]:std::make_pair(i+c,k);
			}
		}
		for(int i=1;i<=a;i++) next[i] = next[i]>next[i-1]?next[i]:next[i-1];
		
		int p = 1;
		ans.clear();
		while(p<=a)
		{
			if(next[p].first<=p)
			{
				printf("-1\n");
				goto u;
			}
			ans.push_back(std::make_pair(next[p].first-len[next[p].second],next[p].second));
			p = next[p].first;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].second,ans[i].first);
		u:;
	}
}