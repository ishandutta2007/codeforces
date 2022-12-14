#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;
int x[100010];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		V1.push_back(x[1]);
		int type = 1;
		if(x[1]<x[2]) type = 1;
		else type = 2;
		
		for(int i=2;i<=a;i++)
		{
			if(type==1)
			{
				if(x[i]<x[i-1])
				{
					if(i==2) break;
					V1.push_back(x[i-1]);
					type = 2;
				}
			}
			else
			{
				if(x[i]>x[i-1])
				{
					V1.push_back(x[i-1]);
					type = 1;
				}
			}
		}
		V1.push_back(x[a]);
		printf("%d\n",V1.size());
		for(int i=0;i<V1.size();i++) printf("%d ",V1[i]);
		printf("\n");
		
	}
}