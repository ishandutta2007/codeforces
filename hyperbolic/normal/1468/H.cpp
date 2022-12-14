#include <stdio.h>
#include <vector>

std::vector<int> V;
int check[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=c;i++)
		{
			int d;
			scanf("%d",&d);
			check[d] = 1;
		}
		for(int i=1;i<=a;i++) if(check[i]==0) V.push_back(i);
		if(V.size()%(b-1)==0)
		{
			int e = (b-1)/2;
			for(int i=0;i+1<V.size();i++)
			{
				if(V[i]+1!=V[i+1])
				{
					if((i+1)>=e&&(V.size()-i-1)>=e)
					{
						printf("YES\n");
						goto u;
					}
				}
			}
			printf("NO\n");
			u:;
		}
		else printf("NO\n");
	}
}