#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int height[100010],sum[100010],check[10];
void func(int k , int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1);
	}
	if(V[k].size()==1) sum[prev]++;
}
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
	
	int root = 1;
	for(int i=1;i<=a;i++) if(V[i].size()>=2) root = i;
	func(root,0,0);
	
	int min,max = a-1;
	
	for(int i=1;i<=a;i++) if(V[i].size()==1) check[height[i]%2]++;
	if(check[0]>0&&check[1]>0) min = 3;
	else min = 1;
	
	for(int i=1;i<=a;i++) if(sum[i]>0) max -= (sum[i]-1);
	printf("%d %d",min,max);
}