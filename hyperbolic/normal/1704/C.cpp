#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+b+1);
		x[b+1] = x[1] + a;
		for(int i=1;i<=b;i++) V.push_back(x[i+1]-x[i]-1);
		std::sort(V.begin(),V.end());
		std::reverse(V.begin(),V.end());
		
		long long int ans = 0;
		int C = 0;
		for(int i=0;i<V.size();i++)
		{
			if(V[i]<=C) continue;
			else if(V[i]==C+1)
			{
				ans++;
				C+=2;
			}
			else if(V[i]==C+2)
			{
				ans++;
				C+=2;
			}
			else
			{
				ans += (V[i]-C-1);
				C+=4;
			}
		}
		printf("%lld\n",a-ans);
	}
}