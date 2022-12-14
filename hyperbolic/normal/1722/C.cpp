#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>

int ans[110];
std::map<int,int> M;
std::vector<int> V[110];
char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=3;i++) V[i].clear();
		M.clear();
		for(int i=1;i<=3;i++) ans[i] = 0;
		int a;
		scanf("%d",&a);
		for(int j=1;j<=3;j++)
		{
			for(int i=1;i<=a;i++)
			{
				scanf("%s",x+1);
				int val = x[1]*27*27 + x[2]*27 + x[3];
				M[val]++;
				V[j].push_back(val);
			}
		}
		
		for(int j=1;j<=3;j++)
		{
			for(int i=0;i<V[j].size();i++)
			{
				if(M[V[j][i]]==1) ans[j]+=3;
				else if(M[V[j][i]]==2) ans[j]++;
			}
		}
		
		printf("%d %d %d\n",ans[1],ans[2],ans[3]);
	}
}