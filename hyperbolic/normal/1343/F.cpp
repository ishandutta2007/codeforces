#include <stdio.h>
#include <algorithm>
#include <vector>
int a;
int check[210],check2[210];
std::vector<int> V[210],V2[210];
int x[210];
int func(int start)
{
	for(int i=1;i<=a;i++) check[i] = check2[i] = 0;
	x[1] = start;
	check2[start] = 1;	
	for(int i=0;i<V2[start].size();i++) check[V2[start][i]]++;
	
	for(int i=2;i<=a;i++)
	{
		int p = 0;
		for(int j=1;j<a;j++)
		{
			if(V[j].size() - check[j] == 1)
			{
				if(p==0)
				{
					for(int k=0;k<V[j].size();k++)
					{
						if(check2[V[j][k]]==0)
						{
							p = V[j][k];
							break;
						}
					}
					
					std::vector<int> V3;
					for(int k=i-V[j].size()+1;k<=i-1;k++) V3.push_back(x[k]);
					V3.push_back(p);
					std::sort(V3.begin(),V3.end());
					for(int k=0;k<V3.size();k++) if(V3[k]!=V[j][k]) return -1;
				}
				else return -1;
			}
		}
		if(p==0) return -1;
		
		x[i] = p;
		check2[p] = 1;
		for(int j=0;j<V2[p].size();j++) check[V2[p][j]]++;
	}
	return 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) V2[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int b;
			scanf("%d",&b);
			for(int j=1;j<=b;j++)
			{
				int c;
				scanf("%d",&c);
				V[i].push_back(c);
				V2[c].push_back(i);
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(func(i)==1)
			{
				for(int j=1;j<=a;j++) printf("%d ",x[j]);
				printf("\n");
				goto u;
			}
		}
		u:;
	}
}