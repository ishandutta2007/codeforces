#include <stdio.h>
#include <vector>

std::vector<int> V;
int check[1000010],x[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++) check[i] = 0;
		for(int i=0;i<a;i++) scanf("%d",&x[i]);
		
		int ans = 0;
		for(int i=0;i<a;i++)
		{
			if(check[i]==0)
			{
				V.clear();
				int p = i;
				while(check[p]==0)
				{
					V.push_back(x[p]);
					check[p] = 1;
					p = (p+b)%a;
				}
				
				int start = -1;
				for(int j=0;j<V.size();j++) if(V[j]==0) start = j;
				if(start==-1)
				{
					printf("-1\n");
					goto u;
				}
				int C = 0;
				int k = start;
				for(int j=0;j<V.size();j++)
				{
					k++;
					k %= V.size();
					if(V[k]==0) C = 0;
					else C++;
					ans = ans>C?ans:C;
				}
			}
		}
		printf("%d\n",ans);
		u:;
	}
}