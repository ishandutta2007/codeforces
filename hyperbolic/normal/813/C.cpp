#include <stdio.h>
#include <vector>

int prev[200010],height[200010],len[200010];
std::vector<int> V[200010];

int func(int k, int p, int h)
{
	prev[k] = p;
	height[k] = h;
	len[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		int t = func(V[k][i],k,h+1);
		len[k] = len[k]>t?len[k]:t;
	}
	return len[k];
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	func(1,0,1);
	
	int p = b;
	int C = 0;
	int ans = 0;
	while(1)
	{
		if(height[p]>C+1)
		{
			ans = ans>len[p]?ans:len[p];
			p = prev[p];
			C++;
		}
		else break;
	}
	printf("%d",2*ans-2);
}