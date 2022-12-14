#include <stdio.h>
#include <algorithm>

char x[5][110][110];
int y[5][110][110];
int p[5];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[1][i]+1);
	for(int i=1;i<=a;i++) scanf("%s",x[2][i]+1);
	for(int i=1;i<=a;i++) scanf("%s",x[3][i]+1);
	for(int i=1;i<=a;i++) scanf("%s",x[4][i]+1);
	
	for(int k=1;k<=4;k++) for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) y[k][i][j] = x[k][i][j]-'0';
	
	int ans = 12345678;
	p[1] = 1, p[2] = 2, p[3] = 3, p[4] = 4;
	do{
		int count = 0;
		for(int k=1;k<=4;k++)
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++) count += (y[k][i][j]+(p[k]+i+j))%2;
			}
		}
		ans = ans<count?ans:count;
	}while(std::next_permutation(p+1,p+5));
	printf("%d",ans);
}