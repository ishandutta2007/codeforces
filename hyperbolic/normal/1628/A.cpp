#include <stdio.h>
#include <vector>

int x[200010];
std::vector<int> ans;
int check[200010],count[200010],count2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) check[i] = count[i] = 0;
		check[a+1] = 123456789;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int p = 0;
		for(int i=a;i>=1;i--)
		{
			count[x[i]]++;
			while(count[p]>0) p++;
			check[i] = p;
		}
		
		int start = 1;
		while(start<=a)
		{
			int val = 0;
			for(int i=start;i<=a;i++)
			{
				count2[x[i]]++;
				while(count2[val]>0) val++;
				if(val==check[start])
				{
					ans.push_back(val);
					for(int j=start;j<=i;j++) count2[x[j]]--;
					start = i+1;
					break;
				}
			}
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		
	}
}