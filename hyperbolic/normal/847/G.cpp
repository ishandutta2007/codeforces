#include <stdio.h>
int x[1010][10];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=7;j++) scanf("%1d",&x[i][j]);
	int ans = 0;
	for(int j=1;j<=7;j++)
	{
		int c = 0;
		for(int i=1;i<=a;i++) c+=x[i][j];
		ans = ans>c?ans:c;
	}
	printf("%d",ans);
}