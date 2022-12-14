#include <stdio.h>
#include <vector>
#include <algorithm>

int x[200010],y[200010];
std::vector<int> V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++)
		{
			if(y[i]-x[i]>=0) V1.push_back(y[i]-x[i]);
			else V2.push_back(x[i]-y[i]);
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		int ans = 0;
		int min = 1, max = V2.size();
		while(min<=max)
		{
			int h = (min+max)/2;
			if(V1.size()<h) max = h-1;
			else
			{
				int control = 0;
				for(int i=0;i<h;i++)
				{
					if(V1[V1.size()-1+i-(h-1)] < V2[i]) control = 1;
				}
				if(control) max = h-1;
				else
				{
					ans = h;
					min = h+1;
				}
			}
		}
		printf("%d\n",(V1.size()+ans)/2);
	}
}