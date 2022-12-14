#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V;
long long int power[20];
int func(long long int v)
{
	int min = 0, max = V.size()-1;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[h]<=v)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	return ans;
}

int main()
{
	power[0] = 1;
	for(int i=1;i<=18;i++) power[i] = 10*power[i-1];
	
	for(int i=0;i<=17;i++)
	{
		for(int j=i+1;j<=17;j++)
		{
			for(int k=j+1;k<=17;k++)
			{
				for(int t1=0;t1<=9;t1++)
				{
					for(int t2=0;t2<=9;t2++)
					{
						for(int t3=0;t3<=9;t3++)
						{
							long long int s = t1*power[i]+t2*power[j]+t3*power[k];
							V.push_back(s);
						}
					}
				}
			}
		}
	}
	V.push_back(power[18]);
	std::sort(V.begin(),V.end());
	V.erase(std::unique(V.begin(),V.end()),V.end());
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		printf("%d\n",func(b)-func(a-1));
	}
}