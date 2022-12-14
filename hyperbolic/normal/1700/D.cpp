#include <stdio.h>
#include <vector>

std::vector<long long int> V;
int x[200010];
long long int y[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = y[i-1] + x[i];
	
	V.push_back(-1);
	long long int M = 0;
	for(int i=1;i<=a;i++)
	{
		long long int val = (y[a]-1)/i+1;
		val = val>M?val:M;
		V.push_back(val);
		M = M>(y[i]-1)/i+1?M:(y[i]-1)/i+1;
	}
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c;
		scanf("%d",&c);
		int min = 1, max = V.size()-1;
		int ans = -1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(V[h]<=c)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d\n",ans);
	}
}