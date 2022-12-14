#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

std::vector<int> V[110];
std::vector< std::pair<int,int> > ans;
char x[200010];
int sum[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<9;i++) V[i].clear();
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) x[i] -= '0';
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		
		int b,c;
		scanf("%d%d",&b,&c);
		
		int val = 0;
		for(int i=1;i<=b-1;i++) val += x[i];
		
		for(int i=b;i<=a;i++)
		{
			val += x[i];
			if(V[val%9].size()<2) V[val%9].push_back(i-b+1);
			val -= x[i-b+1];
		}
		
		while(c--)
		{
			ans.clear();
			int d,e,f;
			scanf("%d%d%d",&d,&e,&f);
			int C = (sum[e]-sum[d-1])%9;
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if((i*C+j)%9!=f) continue;
					for(int i2=0;i2<V[i].size();i2++)
					{
						for(int j2=0;j2<V[j].size();j2++)
						{
							if(V[i][i2]!=V[j][j2]) ans.push_back(std::make_pair(V[i][i2],V[j][j2]));
						}
					}
				}
			}
			if(ans.size()==0) printf("-1 -1\n");
			else
			{
				std::sort(ans.begin(),ans.end());
				printf("%d %d\n",ans[0].first,ans[0].second);
			}
		}
	}
}