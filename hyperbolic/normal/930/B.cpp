#include <stdio.h>
#include <string.h>

int count[30][30][5010];
char x[10010];
int count2[30];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
	
	for(int i=1;i<=a;i++) for(int j=i+1;j<i+a;j++) count[x[i]-'a'+1][x[j]-'a'+1][j-i]++;
	
	double ans = 0;
	for(int i=1;i<=a;i++) count2[x[i]-'a'+1]++;
	for(int i=1;i<=26;i++)
	{
		double max = 0;
		for(int j=1;j<a;j++)
		{
			double sum = 0;
			for(int k=1;k<=26;k++)
			{
				if(count[i][k][j]==1) sum += (double)1/a;
			}
			max = max>sum?max:sum;
		}
		ans += max;
	}
	printf("%.12lf",ans);
}