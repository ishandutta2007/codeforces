#include <stdio.h>
#include <algorithm>
#include <vector>
#define SIZE 8192

std::vector<int> V[5010];
int x[1000010];
int last[10010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) V[x[i]].push_back(i);
	
	for(int j=0;j<=SIZE;j++) last[j] = a+1;
	last[0] = 0;
	
	for(int j=0;j<=5000;j++)
	{
		V[j].push_back(a+1);
		for(int k=0;k<=2*j;k++)
		{
			int val = (k^j);
			
			int min = 0, max = V[j].size()-1;
			int p = V[j].size()-1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[j][h]>=last[k])
				{
					p = h;
					max = h-1;
				}
				else min = h+1;
			}
			last[val] = last[val]<V[j][p]?last[val]:V[j][p];
		}
		//last[j] = last[j] < V[j][0]? last[j] : V[j][0];
	}
	
	int sum = 0;
	for(int i=0;i<=SIZE;i++) if(last[i]<=a) sum++;
	
	printf("%d\n",sum);
	for(int i=0;i<=SIZE;i++) if(last[i]<=a) printf("%d ",i);
}