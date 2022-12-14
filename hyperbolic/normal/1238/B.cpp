#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			V.push_back(c);
		}
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		int p = 123456;
		int C = 0;
		int ans = 0;
		for(int i=V.size()-1;i>=0;i--)
		{
			if(V[i]-C<=0) break;
			if(V[i]-C<p)
			{
				p = V[i]-C;
				ans++;
				C += b;
			}
		}
		printf("%d\n",ans);
	}
}