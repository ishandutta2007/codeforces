#include <stdio.h>

int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	for(int i=1;i<=2*a;i+=2)
	{
		for(int j=i+1;j<=2*a;j++)
		{
			if(x[j]==x[i])
			{
				int t = x[j];
				for(int k=j-1;k>=i+1;k--)
				{
					x[k+1] = x[k];
					count++;
				}
				x[i+1] = t;
			}
		}
	}
	printf("%d\n",count);
}