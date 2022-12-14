#include <stdio.h>
#include <vector>

std::pair<int,int> P[5010];
long long int dist(int s, int t)
{
	long long int s1 = (P[s].first-P[t].first);
	long long int s2 = (P[s].second-P[t].second);
	return s1*s1+s2*s2;
}

int x[5010],check[5010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
	}
	
	x[1] = 1;
	check[1] = 1;
	for(int i=2;i<=a;i++)
	{
		long long int max = 0;
		int ind = 0;
		
		for(int j=1;j<=a;j++)
		{
			if(check[j]) continue;
			long long int d = dist(x[i-1],j);
			if(max<d)
			{
				max = d;
				ind = j;
			}
		}
		x[i] = ind;
		check[ind] = 1;
	}
	
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
}