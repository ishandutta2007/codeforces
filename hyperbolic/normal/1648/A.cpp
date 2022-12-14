#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[100010];
std::vector<int> W[100010];

int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) scanf("%d",&x[j]);
		V[i].push_back(0);
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
	}
	
	long long int ans = 0;
	for(int j=1;j<=100000;j++) W[j].clear();
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) W[V[i][j]].push_back(j);
	for(int j=1;j<=100000;j++)
	{
		std::sort(W[j].begin(),W[j].end());
		
		long long int S = 0, C = 0;
		for(int i=0;i<W[j].size();i++)
		{
			ans += C*W[j][i] - S;
			S += W[j][i], C++;
		}
	}
	
	for(int j=1;j<=100000;j++) W[j].clear();
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) W[V[i][j]].push_back(i);
	for(int j=1;j<=100000;j++)
	{
		std::sort(W[j].begin(),W[j].end());
		
		long long int S = 0, C = 0;
		for(int i=0;i<W[j].size();i++)
		{
			ans += C*W[j][i] - S;
			S += W[j][i], C++;
		}
	}
	printf("%lld",ans);
}