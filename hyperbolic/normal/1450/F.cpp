#include <stdio.h>
#include <map>
#include <vector>

std::map<int,int> M;
int x[100010],count1[100010],count2[100010],count3[100010];
std::vector< std::pair<int,int> > V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		M.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count1[i] = count2[i] = count3[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) M[x[i]]++;
		
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(2*M[x[i]]>a+1)
			{
				control = 1;
			}
		}
		if(control)
		{
			printf("-1\n");
			continue;
		}
		
		int start = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==x[i+1])
			{
				V.push_back(std::make_pair(start,i));
				if(x[start]==x[i])
				{
					if((i-start+1)>=4) count2[x[i]]++;
					else count1[x[i]]++;
				}
				else
				{
					count3[x[i]]++;
					count3[x[start]]++;
				}
				start = i+1;
			}
		}
		if(start<=a)
		{
			V.push_back(std::make_pair(start,a));
			int i = a;
			if(x[start]==x[i])
			{
				if((i-start+1)>=4) count2[x[i]]++;
				else count1[x[i]]++;
			}
			else
			{
				count3[x[i]]++;
				count3[x[start]]++;
			}
		}
		
		int ans = V.size()-1;
		for(int i=1;i<=a;i++)
		{
			//printf("%d %d %d??\n",count1[i],count2[i],count3[i]);
			if((int)V.size()-count1[i]-count2[i]-count3[i]>=count1[i]+count2[i]-1);
			else
			{
				int t = (V.size()-1)+(count1[i]+count2[i]-1)-((int)V.size()-count1[i]-count2[i]-count3[i]);
				//printf("%d %d??\n",i,t);
				ans = ans>t?ans:t;
			}
		}
		
		printf("%d\n",ans);
	}
}