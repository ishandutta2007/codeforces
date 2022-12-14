#include <stdio.h>
#include <queue>

std::vector<int> check[1000010],value[1000010];
std::vector<char> x[1000010];
char y[1000010];

int direX[5] = {0,1,0,-1},direY[5] = {1,0,-1,0};
std::queue< std::pair<int,int> > Q;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+1;i++) check[i].clear();
		for(int i=0;i<=a+1;i++) value[i].clear();
		for(int i=0;i<=a+1;i++) x[i].clear();
		
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i].push_back(0);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) value[i].push_back(0);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i].push_back('#');
		
		for(int i=1;i<=a;i++)
		{
			scanf("%s",y+1);
			for(int j=1;j<=b;j++) x[i][j] = y[j];
		}
		
		std::pair<int,int> start;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='L') start = std::make_pair(i,j);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=0;k<4;k++)
				{
					int s = i+direX[k];
					int t = j+direY[k];
					if(x[s][t]!='#') value[i][j]++;
				}
			}
		}
		
		Q.push(start);
		while(!Q.empty())
		{
			int s = Q.front().first;
			int t = Q.front().second;
			Q.pop();
			
			check[s][t] = 1;
			for(int k=0;k<4;k++)
			{
				int s2 = s+direX[k];
				int t2 = t+direY[k];
				if(x[s2][t2]=='.')
				{
					value[s2][t2]--;
					if(check[s2][t2]==0 && value[s2][t2]<=1)
					{
						check[s2][t2] = 1;
						Q.push(std::make_pair(s2,t2));
					}
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(i==start.first&&j==start.second) printf("L");
				else if(check[i][j]==1) printf("+");
				else printf("%c",x[i][j]);
			}
			printf("\n");
		}
	}
}