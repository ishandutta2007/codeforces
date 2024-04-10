#include <stdio.h>
#include <algorithm>
#include <vector>

int count[5010];
int num[3][5010];
int get(int s, int t, int type)
{
	return num[type][t] - num[type][s-1];
}

std::pair<int,int> P[5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d%d",&P[i].first,&P[i].second);
	std::sort(P+1,P+b+1);
	for(int i=1;i<=b;i++) for(int j=P[i].first;j<=P[i].second;j++) count[j]++;
	for(int i=1;i<=a;i++) if(count[i]==1) num[1][i] = 1;
	for(int i=1;i<=a;i++) num[1][i] += num[1][i-1];
	for(int i=1;i<=a;i++) if(count[i]==2) num[2][i] = 1;
	for(int i=1;i<=a;i++) num[2][i] += num[2][i-1];
	
	int S = 0;
	for(int i=1;i<=a;i++) if(count[i]>0) S++;
	int ans = S;
	for(int i=1;i<=b;i++)
	{
		for(int j=i+1;j<=b;j++)
		{
			if(P[i].second<P[j].first)
			{
				int C = get(P[i].first,P[i].second,1)+get(P[j].first,P[j].second,1);
				ans = ans<C?ans:C;
			}
			else
			{
				if(P[j].second<P[i].second)
				{
					int C = get(P[i].first,P[j].first-1,1)+get(P[j].first,P[j].second,2)+get(P[j].second+1,P[i].second,1);
					ans = ans<C?ans:C;
				}
				else
				{
					int C = get(P[i].first,P[j].first-1,1)+get(P[j].first,P[i].second,2)+get(P[i].second+1,P[j].second,1);
					ans = ans<C?ans:C;
				}
			}
		}
	}
	printf("%d",S-ans);
}