#include <stdio.h>

char x[110],y[110];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		int control = -1;
		for(int j=1;j<=3;j++) if(y[j]!=x[j]) goto u;
		control = 1;
		u:;
		ans += control;
	}
	if(ans==0) printf("home");
	else printf("contest");
}