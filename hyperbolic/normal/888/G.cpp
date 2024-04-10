#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1<<30;

int bit(int val, int k)
{
	return (val/(1<<k))%2;
}

long long int ans = 0;

int next[6000010][2];
int level[6000010];

int find(int s, int t, int val1)
{
	if(level[s]==0)
	{
		int sum = (1<<level[t]);
		int p = t;
		while(level[p])
		{
			if(next[p][bit(val1,level[p]-1)]!=0) p = next[p][bit(val1,level[p]-1)];
			else if(next[p][1-bit(val1,level[p]-1)]!=0)
			{
				p = next[p][1-bit(val1,level[p]-1)];
				sum += (1<<level[p]);
			}
			else break;
		}
		return sum;
	}
	else
	{
		int s0 = MAX;
		int s1 = MAX;
		if(next[s][0]!=0) s0 = find(next[s][0],t,2*val1);
		if(next[s][1]!=0) s1 = find(next[s][1],t,2*val1+1);
		return s0<s1?s0:s1;
	}
}
void func(int k)
{
	if(next[k][0]!=0) func(next[k][0]);
	if(next[k][1]!=0) func(next[k][1]);
	if(next[k][0]!=0 && next[k][1]!=0)
	{
		int min = find(next[k][0],next[k][1],0);
		ans += min;
	}
}

std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	
	int C = 2;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		int b2 = b;
		
		V.clear();
		for(int j=0;j<30;j++) V.push_back(b%2), b/=2;
		std::reverse(V.begin(),V.end());
		
		int start = 1;
		int sum = 0;
		for(int j=0;j<V.size();j++)
		{
			if(next[start][V[j]]==0) next[start][V[j]] = C++;
			start = next[start][V[j]];
			level[start] = 29-j;
		}
	}
	
	func(1);
	printf("%lld",ans);
}