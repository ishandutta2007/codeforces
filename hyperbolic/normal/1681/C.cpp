#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++)
		{
			int p = i;
			for(int j=i+1;j<=a;j++)
			{
				if(x[j]<x[p]) p = j;
				else if(x[j]==x[p]&&y[j]<y[p]) p = j;
			}
			if(p==i) continue;
			ans.push_back(std::make_pair(i,p));
			int temp;
			temp = x[i];
			x[i] = x[p];
			x[p] = temp;
			temp = y[i];
			y[i] = y[p];
			y[p] = temp;
		}
		
		for(int i=1;i<a;i++)
		{
			if(y[i]>y[i+1])
			{
				printf("-1\n");
				goto u;
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
		u:;
	}
}