#include <stdio.h>
#include <vector>

std::vector<int> V[250010];
std::vector<int> index;
int a,b;
int limit[250010],ans[250010];
void func(int s, int t)
{
	for(int i=1;i<=a;i++) limit[i] = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(j==s) continue;
			if(j==t) continue;
			if(V[i][j]!=ans[j]) limit[i]++;
		}
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			V[i].push_back(c);
		}
	}
	
	int p1,p2;
	for(int i=2;i<=a;i++)
	{
		int count = 0;
		for(int j=0;j<b;j++) if(V[i][j]!=V[1][j]) count++;
		if(count>=3)
		{
			p1 = 1;
			p2 = i;
			goto u;
		}
	}
	
	printf("Yes\n");
	for(int j=0;j<b;j++) printf("%d ",V[1][j]);
	return 0;
	
	u:;
	
	for(int j=0;j<b;j++) if(V[p1][j]!=V[p2][j]) index.push_back(j);
	if(index.size()>=5)
	{
		printf("No");
		return 0;
	}
	
	for(int i1=0;i1<index.size();i1++)
	{
		for(int i2=i1+1;i2<index.size();i2++)
		{
			for(int j=0;j<b;j++) ans[j] = V[1][j];
			func(index[i1],index[i2]);
			
			for(int i=1;i<=a;i++) if(limit[i]>=3) goto v;
			
			for(int i=1;i<=a;i++)
			{
				if(limit[i]==2)
				{
					ans[index[i1]] = V[i][index[i1]];
					ans[index[i2]] = V[i][index[i2]];
					func(-1,-1);
					for(int j=1;j<=a;j++) if(limit[j]>=3) goto v;
					
					printf("Yes\n");
					for(int k=0;k<b;k++) printf("%d ",ans[k]);
					return 0;
				}
			}
			
			for(int i=1;i<=a;i++)
			{
				if(limit[i]==1)
				{
					ans[index[i2]] = V[i][index[i2]];
					func(index[i1],-1);
					/*printf("%d %d??\n",index[i1],index[i2]);
					for(int j=0;j<b;j++) printf("%d ",ans[j]);
					printf("??\n");
					for(int j=1;j<=a;j++) printf("%d ",limit[j]);
					printf("!!\n");*/
					
					for(int j=1;j<=a;j++) if(limit[j]>=3) goto v1;
					for(int j=1;j<=a;j++)
					{
						if(limit[j]==2)
						{
							ans[index[i1]] = V[j][index[i1]];
							func(-1,-1);
							for(int k=1;k<=a;k++) if(limit[k]>=3) goto v1;
							printf("Yes\n");
							for(int k=0;k<b;k++) printf("%d ",ans[k]);
							return 0;
						}
					}
					printf("Yes\n");
					for(int k=0;k<b;k++) printf("%d ",ans[k]);
					return 0;
					
					v1:;
					ans[index[i1]] = V[i][index[i1]];
					func(index[i2],-1);
					for(int j=1;j<=a;j++) if(limit[j]>=2) goto v;
					for(int j=1;j<=a;j++)
					{
						if(limit[j]==2)
						{
							ans[index[i2]] = V[j][index[i2]];
							func(-1,-1);
							for(int k=1;k<=a;k++) if(limit[k]>=3) goto v;
							printf("Yes\n");
							for(int k=0;k<b;k++) printf("%d ",ans[k]);
							return 0;
						}
					}
					printf("Yes\n");
					for(int k=0;k<b;k++) printf("%d ",ans[k]);
					return 0;
				}
			}
			
			printf("Yes\n");
			for(int k=0;k<b;k++) printf("%d ",ans[k]);
			return 0;
			v:;
		}
	}
	printf("No");
}