#include <stdio.h>
#include <queue>

std::queue<int> Q;
int x[100010],save[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		save[0] = x[0];
		for(int j=1;j<i;j++) save[j] = x[j]-x[j-1];
		for(int j=i;j<a;j++)
		{
			if(x[j]!=save[j%i]+x[j-1])
			{
				goto u;
			}
		}
		Q.push(i);
		
		u:;
	}
	printf("%d\n",Q.size());
	while(!Q.empty()) printf("%d ",Q.front()),Q.pop();
}