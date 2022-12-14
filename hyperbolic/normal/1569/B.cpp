#include <stdio.h>
#include <vector>

char x[110];
std::vector<int> V;
char ans[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		for(int i=1;i<=a;i++) if(x[i]=='2') V.push_back(i);
		if(V.size()==0)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++)
				{
					if(i==j) printf("X");
					else printf("=");
				}
				printf("\n");
			}
		}
		else if(V.size()<=2) printf("NO\n");
		else
		{
			int p1 = V[0], p2 = V[1], p3 = V[2];
			for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ans[i][j] = '=';
			for(int i=1;i<=a;i++) ans[p1][i] = '-';
			for(int i=1;i<=a;i++) ans[p2][i] = '-';
			for(int i=1;i<=a;i++) ans[p3][i] = '-';
			for(int i=1;i<=a;i++) ans[i][p1] = '+';
			for(int i=1;i<=a;i++) ans[i][p2] = '+';
			for(int i=1;i<=a;i++) ans[i][p3] = '+';
			ans[p1][p2] = '+', ans[p2][p1] = '-';
			ans[p2][p3] = '+', ans[p3][p2] = '-';
			ans[p3][p1] = '+', ans[p1][p3] = '-';
			for(int i=1;i<=a;i++) ans[i][i] = 'X';
			
			printf("YES\n");
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++) printf("%c",ans[i][j]);
				printf("\n");
			}
		}
	}
}