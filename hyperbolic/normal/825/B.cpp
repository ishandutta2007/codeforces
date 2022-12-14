#include <stdio.h>

char x[110][110];
int dire[3][6] = {{-2,-1,0,1,2},{0,0,0,0,0},{2,1,0,-1,-2}};
int func(int s, int t)
{
	for(int type1=0;type1<=2;type1++)
	{
		for(int type2=0;type2<=2;type2++)
		{
			if(type1==1&&type2==1) continue;
			for(int i=0;i<=4;i++) if(x[s+dire[type1][i]][t+dire[type2][i]]!='X') goto u;
			return 1;
			u:;
		}
	}
	return 0;
}
int main()
{
	for(int i=3;i<=12;i++) scanf("%s",x[i]+3);
	for(int i=3;i<=12;i++)
	{
		for(int j=3;j<=12;j++)
		{
			if(x[i][j]=='.')
			{
				x[i][j] = 'X';
				for(int k=3;k<=12;k++)
				{
					for(int l=3;l<=12;l++)
					{
						int t = func(k,l);
						if(t==1)
						{
							printf("YES");
							return 0;
						}
					}
				}
				x[i][j] = '.';
			}
		}
	}
	printf("NO");
}