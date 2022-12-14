#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<int,int> > V1,V2;
int x[1010],y[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear(),V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++)
		{
			V1.push_back(std::make_pair(x[i],x[a-i+1]));
			V2.push_back(std::make_pair(y[i],y[a-i+1]));
		}
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		for(int i=0;i<a;i++)
		{
			if(V1[i]!=V2[i])
			{
				printf("No\n");
				goto u;
			}
		}
		
		printf("Yes\n");
		u:;
	}
}