#include <stdio.h>

int x[5][5];
int main()
{
	int a;
	scanf("%d",&a);
	int MAX = (1<<18)-1;
	x[1][1] = MAX, x[1][2] = MAX, x[1][3] = (1<<17);
	x[2][1] = MAX, x[2][2] = a, x[2][3] = MAX;
	x[3][1] = (1<<17), x[3][2] = MAX, x[3][3] = a;
	printf("3 3\n");
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++) printf("%d ",x[i][j]);
		printf("\n");
	}
}