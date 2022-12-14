#include <stdio.h>
#include <vector>

char x[1010][1010];
int value[1010][1010];
std::pair<int,int> next[1010][1010];
std::pair<int,int> find(std::pair<int,int> P)
{
	if(next[P.first][P.second]==P) return P;
	else return next[P.first][P.second] = find(next[P.first][P.second]);
}

int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) next[i][j] = {i,j};
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.')
			{
				for(int k=0;k<4;k++)
				{
					int s = i+direX[k];
					int t = j+direY[k];
					if(x[s][t]=='.')
					{
						std::pair<int,int> v1 = find({i,j});
						std::pair<int,int> v2 = find({s,t});
						next[v1.first][v1.second] = v2;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='*')
			{
				for(int k=0;k<4;k++)
				{
					int s = i+direX[k];
					int t = j+direY[k];
					if(x[s][t]=='.')
					{
						std::pair<int,int> P = find({s,t});
						value[P.first][P.second]++;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		std::pair<int,int> P = find({d,e});
		printf("%d\n",value[P.first][P.second]);
	}
}