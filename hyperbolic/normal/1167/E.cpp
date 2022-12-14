#include <stdio.h>
#include <vector>

std::vector<int> V[1000010];
int x[1000010];
int max2[1000010],min2[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) V[x[i]].push_back(i);
	
	int m1 = 1,M1 = b,m2 = 1,M2 = b;
	
	int min = a+1;
	for(int i=b;i>=1;i--)
	{
		if(V[i].size()>0)
		{
			if(min<V[i].back())
			{
				m2 = i;
				M2 = b;
				break;
			}
			else min = V[i][0];
		}
	}
	
	int max = 0;
	for(int i=1;i<=b;i++)
	{
		if(V[i].size()>0)
		{
			if(max>V[i][0])
			{
				m1 = 1;
				M1 = i;
				break;
			}
			else max = V[i].back();
		}
	}
	
	max2[0] = 0, min2[b+1] = a+1;
	for(int i=1;i<=b;i++)
	{
		max2[i] = max2[i-1];
		if(V[i].size()>0) max2[i] = max2[i] > V[i].back()? max2[i] : V[i].back();
	}
	for(int i=b;i>=1;i--)
	{
		min2[i] = min2[i+1];
		if(V[i].size()>0) min2[i] = min2[i] < V[i][0]? min2[i] : V[i][0];
	}
	
	long long int ans = 0;
	for(int i=m2;i<=M2;i++)
	{
		int L = m1, R = M1<i?M1:i;
		int p = m1-1;
		while(L<=R)
		{
			int h = (L+R)/2;
			if(max2[h-1]<min2[i+1])
			{
				p = h;
				L = h+1;
			}
			else R = h-1;
		}
		
		ans += (p-m1+1);
	}
	printf("%lld",ans);
}