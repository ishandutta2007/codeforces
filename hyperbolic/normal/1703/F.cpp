#include <stdio.h>
#include <vector>
int x[200010];
std::vector<int> V;
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
		long long int ans2 = 0;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]<i)
			{
				if(!V.empty())
				{
					int ans = -1;
					int min = 0, max = V.size()-1;
					while(min<=max)
					{
						int h = (min+max)/2;
						if(V[h]<x[i])
						{
							ans = h;
							min = h+1;
						}
						else max = h-1;
					}
					ans2 += (ans+1);
				}
				V.push_back(i);
			}
		}
		printf("%lld\n",ans2);
	}
}