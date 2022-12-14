#include <stdio.h>
#include <vector>

char x[310][310];
std::vector< std::pair<int,int> > V[5];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=2;i++) V[i].clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]!='.') V[(i+j)%3].push_back(std::make_pair(i,j));
				if(x[i][j]!='.') count++;
			}
		}
		
		for(int i=0;i<=2;i++)
		{
			if(3*V[i].size()<=count)
			{
				for(int j=0;j<V[i].size();j++)
				{
					int s = V[i][j].first;
					int t = V[i][j].second;
					if(s>=3 && x[s-1][t]=='X'&&x[s-2][t]=='X') x[s][t] = 'O';
					if(s<=a-2 && x[s+1][t]=='X'&&x[s+2][t]=='X') x[s][t] = 'O';
					if(t>=3 && x[s][t-1]=='X'&&x[s][t-2]=='X') x[s][t] = 'O';
					if(t<=a-2 && x[s][t+1]=='X'&&x[s][t+2]=='X') x[s][t] = 'O';
					if(s>=2 && s<=a-1 && x[s-1][t]=='X' && x[s+1][t]=='X') x[s][t] = 'O';
					if(t>=2 && t<=a-1 && x[s][t-1]=='X' && x[s][t+1]=='X') x[s][t] = 'O';
				}
				goto u;
			}
		}
		u:;
		
		printf("\n");
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%c",x[i][j]);
			printf("\n");
		}
	}
}