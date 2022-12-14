#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int value1;
	int value2;
	int index;
};
bool cmp(str a, str b)
{
	return a.first<b.first;
}
std::vector<str> V2;

std::vector<int> V[500010],left[500010],right[500010],left2[500010],right2[500010];
int x[500010],max[1000010],min[1000010];
char ans[1000010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) left[i].clear();
		for(int i=1;i<=a;i++) right[i].clear();
		for(int i=1;i<=a;i++) left2[i].clear();
		for(int i=1;i<=a;i++) right2[i].clear();
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) scanf("%d",&x[j]);
			V[i].push_back(0);
			for(int j=1;j<=b;j++) V[i].push_back(x[j]);
			V[i].push_back(0);
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<=b+1;j++) left[i].push_back(0);
			for(int j=0;j<=b+1;j++) right[i].push_back(0);
			for(int j=0;j<=b+1;j++) left2[i].push_back(0);
			for(int j=0;j<=b+1;j++) right2[i].push_back(0);
			
			left[i][1] = V[i][1];
			for(int j=2;j<=b;j++) left[i][j] = left[i][j-1]>V[i][j]?left[i][j-1]:V[i][j];
			right[i][b] = V[i][b];
			for(int j=b-1;j>=1;j--) right[i][j] = right[i][j+1]>V[i][j]?right[i][j+1]:V[i][j];
			
			left2[i][1] = V[i][1];
			for(int j=2;j<=b;j++) left2[i][j] = left2[i][j-1]<V[i][j]?left2[i][j-1]:V[i][j];
			right2[i][b] = V[i][b];
			for(int j=b-1;j>=1;j--) right2[i][j] = right2[i][j+1]<V[i][j]?right2[i][j+1]:V[i][j];
		}
		
		for(int j=1;j<b;j++)
		{
			V2.clear();
			
			
			for(int i=1;i<=a;i++) V2.push_back({left[i][j],right[i][j+1],left2[i][j],right2[i][j+1],i});
			std::sort(V2.begin(),V2.end(),cmp);
			
			min[V2.size()] = 12345678;
			for(int i=V2.size()-1;i>=0;i--) min[i] = min[i+1]<V2[i].value1?min[i+1]:V2[i].value1;
			
			max[V2.size()] = 0;
			for(int i=V2.size()-1;i>=0;i--) max[i] = max[i+1]>V2[i].second?max[i+1]:V2[i].second;
			
			int limit = V2[0].first;
			int limit2 = V2[0].value2;
			for(int i=0;i<=V2.size()-2;i++)
			{
				limit = limit>V2[i].first?limit:V2[i].first;
				limit2 = limit2<V2[i].value2?limit2:V2[i].value2;
				if(limit < min[i+1] && limit2 > max[i+1])
				{
					for(int j=0;j<=i;j++) ans[V2[j].index] = 'B';
					for(int j=i+1;j<V2.size();j++) ans[V2[j].index] = 'R';
					
					printf("YES\n");
					for(int j=1;j<=a;j++) printf("%c",ans[j]);
					printf(" %d\n",j);
					goto u;
				}
			}
		}
		printf("NO\n");
		u:;
	}
}