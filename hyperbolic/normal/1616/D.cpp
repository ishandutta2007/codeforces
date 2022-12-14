#include <stdio.h>
#include <vector>

std::vector< std::pair<long long int,int> > V;
int findMax(long long int R)
{
	if(V.size()==0) return -1;
	int min = 0, max = V.size()-1;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[h].first>R)
		{
			ans = V[h].second;
			min = h+1;
		}
		else max = h-1;
	}
	return ans;
}

int x[50010];
int ans[50010][3],last[50010][3];
long long int sum[50010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1]+x[i];
		
		int b;
		scanf("%d",&b);
		ans[0][0] = 0;
		ans[0][1] = -1;
		for(int i=1;i<=a;i++)
		{
			if(ans[i-1][0]>ans[i-1][1])
			{
				ans[i][0] = ans[i-1][0];
				last[i][0] = i;
			}
			else
			{
				ans[i][0] = ans[i-1][1];
				last[i][0] = i;
			}
			
			ans[i][1] = ans[i-1][0]+1;
			last[i][1] = last[i-1][0];
			
			long long int val = sum[i]-(long long int)b*i;
			int t = findMax(val)+1;
			if(t>last[i-1][1])
			{
				if(ans[t][0]+(i-t)>ans[i][1])
				{
					ans[i][1] = ans[t][0] + (i-t);
					last[i][1] = t;
				}
			}
			else
			{
				if(ans[i-1][1]+1>ans[i][1])
				{
					ans[i][1] = ans[i-1][1] + 1;
					last[i][1] = last[i-1][1];
				}
			}
			
			val = sum[i-1]-(long long int)b*(i-1);
			while(!V.empty() && V.back().first<=val) V.pop_back();
			V.push_back(std::make_pair(val,i-1));
		}
		
		printf("%d\n",ans[a][1]>ans[a][0]?ans[a][1]:ans[a][0]);
	}
}