#include <stdio.h>
#include <vector>

std::vector<int> V[100010],V2[100010];
int ans[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V2[i].clear();
		for(int j=1;j<=b;j++) V[j].clear();
		
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			for(int j=1;j<=c;j++)
			{
				int d;
				scanf("%d",&d);
				V[i].push_back(d);
				V2[d].push_back(i);
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(V2[i].size()>=(b+1)/2)
			{
				int count = 0;
				for(int j=0;j<V2[i].size();j++) if(V[V2[i][j]].size()==1) count++;
				if(count<=(b+1)/2)
				{
					int C = (b+1)/2;
					printf("YES\n");
					
					for(int j=1;j<=b;j++) ans[j] = 0;
					for(int j=0;j<V2[i].size();j++)
					{
						if(V[V2[i][j]].size()==1)
						{
							ans[V2[i][j]] = i;
							C--;
						}
					}
					for(int j=0;j<V2[i].size();j++)
					{
						if(V[V2[i][j]].size()>1 && C>0)
						{
							ans[V2[i][j]] = i;
							C--;
						}
					}
					for(int j=1;j<=b;j++)
					{
						if(ans[j]==0)
						{
							for(int k=0;k<V[j].size();k++)
							{
								if(V[j][k]==i) continue;
								ans[j] = V[j][k];
								break;
							}
						}
					}
					
					for(int j=1;j<=b;j++) printf("%d ",ans[j]);
					printf("\n");
					
					goto u;
				}
				else
				{
					printf("NO\n");
					goto u;
				}
			}
		}
		
		printf("YES\n");
		for(int i=1;i<=b;i++) printf("%d ",V[i][0]);
		printf("\n");
		
		u:;
	}
}