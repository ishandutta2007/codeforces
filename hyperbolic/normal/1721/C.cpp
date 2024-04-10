#include <stdio.h>
#include <set>
#include <vector>

int x[200010],y[200010];
int min[200010],max[200010];
std::set<int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) max[i] = 1234567890;
		S.clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int p;
		p = 1;
		for(int i=1;i<=a;i++)
		{
			while(p<=a&&y[p]<x[i]) p++;
			// 1 ~ p-1
			if(p==i) max[i-1] = y[p-1];
		}
		max[a] = y[a];
		for(int i=a-1;i>=1;i--) max[i] = max[i]<max[i+1]?max[i]:max[i+1];
		
		p = 1;
		for(int i=1;i<=a;i++)
		{
			while(p<=a&&y[p]<x[i]) S.insert(y[p++]);
			// 1 ~ p-1
			min[i] = y[p];
		}
		
		for(int i=1;i<=a;i++) printf("%d ",min[i]-x[i]);
		printf("\n");
		for(int i=1;i<=a;i++) printf("%d ",max[i]-x[i]);
		printf("\n");
	}
}