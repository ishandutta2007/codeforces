#include <stdio.h>
#include <vector>

char x[410][410];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		std::pair<int,int> P1={0,0},P2={0,0};
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++)
		{
			int count = 0;
			for(int j=1;j<=a;j++) if(x[i][j]=='*') count++;
			if(count==2)
			{
				if(i==1)
				{
					for(int j=1;j<=a;j++) if(x[i][j]=='*') x[i+1][j] = '*';
				}
				else
				{
					for(int j=1;j<=a;j++) if(x[i][j]=='*') x[i-1][j] = '*';
				}
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			int count = 0;
			for(int j=1;j<=a;j++) if(x[j][i]=='*') count++;
			if(count==2)
			{
				if(i==1)
				{
					for(int j=1;j<=a;j++) if(x[j][i]=='*') x[j][i+1] = '*';
				}
				else
				{
					for(int j=1;j<=a;j++) if(x[j][i]=='*') x[j][i-1] = '*';
				}
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]=='*')
				{
					if(P1.first==0) P1 = {i,j};
					else P2 = {i,j};
				}
			}
		}
		x[P1.first][P2.second] = x[P2.first][P1.second] = '*';
		
		u:;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%c",x[i][j]);
			printf("\n");
		}
	}
}