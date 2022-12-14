#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int check[200010];

int main()
{
	for(int j=2;j<=200000;j*=2) for(int i=j;i<=200000;i+=j) check[i]++;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int C = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			while(b%2==0) C++, b/=2;
		}
		if(C>=a) printf("0\n");
		else
		{
			V.clear();
			for(int i=1;i<=a;i++) V.push_back(check[i]);
			std::sort(V.begin(),V.end());
			std::reverse(V.begin(),V.end());
			for(int i=0;i<V.size();i++)
			{
				C += V[i];
				if(C>=a)
				{
					printf("%d\n",i+1);
					goto u;
				}
			}
			printf("-1\n");
			u:;
		}
	}
}