#include <stdio.h>
#include <vector>

int check[1010],check2[1010];
std::vector<int> V[1010];

void func(int k, int &C)
{
	if(check[k]) return;
	for(int i=0;i<V[k].size();i++) func(V[k][i],C);
	check[k] = C++;
	check2[check[k]] = k;
}

int ans[1010][1010];
char x[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = 0;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(x[i][j]=='1') V[i].push_back(j);
		
		int C = 1;
		for(int i=1;i<=a;i++) func(i,C);
		
		for(int i=a;i>=1;i--)
		{
			int ind = check2[i];
			ans[ind][ind] = 1;
			for(int j=0;j<V[ind].size();j++)
			{
				for(int k=1;k<=a;k++)
				{
					if(ans[ind][k]==1) ans[V[ind][j]][k] = 1;
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			int S = 0;
			for(int j=1;j<=a;j++) S += ans[i][j];
			printf("%d ",S);
			for(int j=1;j<=a;j++) if(ans[i][j]==1) printf("%d ",j);
			printf("\n");
		}
	}
}