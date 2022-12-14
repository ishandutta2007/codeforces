#include <stdio.h>
#include <vector>

std::vector<int> V[1010];
int x[1010];

void func(int k)
{
	int count = 0;
	if(V[k].size()==0)
	{
		x[k] = 1;
		return;
	}
	
	for(int i=0;i<V[k].size();i++)
	{
		func(V[k][i]);
		if(x[V[k][i]]==1) count++;
	}
	if(count>=3) x[k] = 2;
	else x[k] = -1;
}
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		scanf("%d",&b);
		V[b].push_back(i);
	}
	func(1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]==-1)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}