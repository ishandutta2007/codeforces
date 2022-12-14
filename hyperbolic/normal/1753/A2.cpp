#include <stdio.h>
#include <vector>

int x[200010],check[200010];
int min[200010],max[200010];
std::vector< std::pair<int,int> > ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(a==1)
		{
			if(x[1]==0)
			{
				printf("1\n");
				printf("1 1\n");
			}
			else printf("-1\n");
			continue;
		}
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if((sum+2000000)%2==1)
		{
			printf("-1\n");
			continue;
		}
		
		sum/=2;
		max[a+1] = min[a+1] = 0;
		max[a+2] = min[a+2] = 0;
		for(int i=a;i>=1;i--)
		{
			int L,R;
			R = max[i+2]+x[i]>max[i+1]?max[i+2]+x[i]:max[i+1];
			L = min[i+2]+x[i]<min[i+1]?min[i+2]+x[i]:min[i+1];
			max[i] = R, min[i] = L;
		}
		if(min[2]<=0&&0<=max[2])
		{
			for(int i=1;i<=a+1;i++) check[i] = 0;
			int p = 2;
			int val = 0;
			while(p<=a)
			{
				if(min[p+2]<=sum-(val+x[p])&&sum-(val+x[p])<=max[p+2])
				{
					check[p] = 1;
					val += x[p];
					p += 2;
				}
				else p++;
			}
			
			p = 1;
			ans.clear();
			while(p<=a)
			{
				if(check[p+1]==0)
				{
					ans.push_back(std::make_pair(p,p));
					p++;
				}
				else
				{
					ans.push_back(std::make_pair(p,p+1));
					p+=2;
				}
			}
			
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
		}
		else printf("-1\n");
	}
}