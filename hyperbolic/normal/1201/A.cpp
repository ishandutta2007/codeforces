#include <stdio.h>

char x[1010][1010];
int y[1010],sum[10];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	int ans = 0;
	for(int j=1;j<=b;j++)
	{
		for(int i=0;i<=5;i++) sum[i] = 0;
		for(int i=1;i<=a;i++) sum[x[i][j]-'A']++;
		int max = sum[0];
		for(int i=1;i<=4;i++) max = max>sum[i]?max:sum[i];
		ans += max*y[j];
	}
	printf("%d",ans);
}