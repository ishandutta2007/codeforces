#include <stdio.h>
#include <vector>
#define MIN -123456789

std::vector<int> V[5010];
int max[5010][5010],max2[5010][5010],x[5010];
int getCount(int num, int L, int R)
{
	if(V[num].size()==0) return 0;
	
	int min,max;
	min = 0, max = V[num].size()-1;
	int l = V[num].size() ,r = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[num][h]>=L)
		{
			l = h;
			max = h-1;
		}
		else min = h+1;
	}
	min = 0, max = V[num].size()-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[num][h]<=R)
		{
			r = h;
			min = h+1;
		}
		else max = h-1;
	}
	return (r-l+1);
}

int value[5010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) V[i].push_back(0);
		for(int i=1;i<=a;i++) V[x[i]].push_back(i);
		for(int i=1;i<=a;i++) V[i].push_back(a+1);
		
		for(int i=1;i<=a;i++)
		{
			max[i][i] = x[i];
			max2[i][i] = 1;
			for(int j=i+1;j<=a;j++)
			{
				if(max[i][j-1]==x[j])
				{
					max[i][j] = max[i][j-1];
					max2[i][j] = max2[i][j-1] + 1;
				}
				else
				{
					int val1 = max2[i][j-1];
					int val2 = getCount(x[j],i,j);
					if(val1>val2)
					{
						max[i][j] = max[i][j-1];
						max2[i][j] = max2[i][j-1];
					}
					else
					{
						max[i][j] = x[j];
						max2[i][j] = val2;
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			value[0] = 0;
			for(int j=1;j<V[i].size();j++)
			{
				value[V[i][j]] = MIN;
				for(int k=0;k<j;k++)
				{
					int len = (V[i][j]-1) - (V[i][k]+1) + 1;
					if(2*max2[V[i][k]+1][V[i][j]-1]<=len&&len%2==0)
					{
						int val = value[V[i][k]] + 1;
						value[V[i][j]] = value[V[i][j]]>val?value[V[i][j]]:val;
					}
				}
			}
			ans = ans>value[a+1]?ans:value[a+1];
		}
		printf("%d\n",ans-1);
	}
}