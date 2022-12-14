#include <stdio.h>
#include <vector>

std::vector<int> M[600010];
int value[300010],sum[300010];
char x[300010];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(i%2==1 && x[i]=='+') value[i] = 1;
			if(i%2==1 && x[i]=='-') value[i] = -1;
			if(i%2==0 && x[i]=='+') value[i] = -1;
			if(i%2==0 && x[i]=='-') value[i] = 1;
		}
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + value[i];
		for(int i=0;i<=a;i++) M[sum[i]+300000].push_back(i);
		
		for(int i=1;i<=b;i++)
		{
			V.clear();
			int c,d;
			scanf("%d%d",&c,&d);
			int S = sum[d] - sum[c-1];
			if(S==0)
			{
				printf("0\n");
				continue;
			}
			else if(S%2==0)
			{
				V.push_back(c);
				c++;
				S = sum[d] - sum[c-1];
				if(S==0)
				{
					printf("1\n");
					printf("%d\n",V[0]);
					continue;
				}
			}
			
			int T;
			if(S>0) T = (S+1)/2;
			else T = -((-S+1)/2);
			T += sum[c-1]+300000;
			
			int min = 0, max = M[T].size()-1;
			int p = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(M[T][h]>=c)
				{
					p = M[T][h];
					max = h-1;
				}
				else min = h+1;
			}
			V.push_back(p);
			
			printf("%d\n",V.size());
			for(int i=0;i<V.size();i++) printf("%d ",V[i]);
			printf("\n");
		}
		for(int i=0;i<=a;i++) M[sum[i]+300000].clear();
	}
}