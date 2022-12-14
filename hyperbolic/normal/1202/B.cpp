#include <stdio.h>
#include <string.h>
#define MAX 123456789

char x[2000010];
int next[20][20][20];
int check[20][20];
int main()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int p = i;
				int count = 0;
				while(1)
				{
					p = (p+k)%10;
					count++;
					if(count>10) goto u;
					if(p==j) break;
				}
				next[i][j][k] = count-1;
				continue;
				
				u:;
				next[i][j][k] = MAX;
 			}
		}
	}
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int i1=0;i1<=9;i1++)
			{
				for(int j1=0;j1<=9;j1++)
				{
					int s = MAX;
					int s1 = next[i1][j1][i];
					s = s<s1?s:s1;
					s1 = next[i1][j1][j];
					s = s<s1?s:s1;
					for(int k=0;k<=9;k++)
					{
						int s2 = next[i1][k][i];
						int s3 = next[k][j1][j];
						s = s<s2+s3+1?s:s2+s3+1;
					}
					check[i1][j1] = s;
				}
			}
			
			long long int count = 0;
			for(int k=1;k<a;k++) count += check[x[k]-'0'][x[k+1]-'0'];
			if(count>=MAX) printf("-1 ");
			else printf("%lld ",count);
		}
		printf("\n");
	}
}