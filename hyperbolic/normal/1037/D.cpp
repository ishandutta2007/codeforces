#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> V[200010];
bool find(int value, std::vector<int> &V)
{
	int min = 0, max = V.size()-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[h]==value) return true;
		if(V[h]<value) min = h+1;
		else max = h-1;
	}
	return false;
}

int x[200010];
std::queue<int> Q;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	V[1].push_back(0);
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	Q.push(1);
	
	if(x[1]!=1)
	{
		printf("No");
		return 0;
	}
	
	int pivot = 2;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		
		int count = V[k].size()-1;
		while(count--)
		{
			if(!find(x[pivot],V[k]))
			{
				printf("No");
				return 0;
			}
			else Q.push(x[pivot++]);
		}
	}
	printf("Yes");
}