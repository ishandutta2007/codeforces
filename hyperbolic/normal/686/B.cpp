#include <stdio.h>
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<a;j++)
		{
			if(x[j]>x[j+1])
			{
				printf("%d %d\n",j,j+1);
				int t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;
			}
		}
	}
}