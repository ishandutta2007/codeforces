#include <stdio.h>

int save[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int p = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b==1)
			{
				p++;
				save[p] = 1;
			}
			else
			{
				for(int j=p;j>=1;j--)
				{
					if(b==save[j]+1)
					{
						p = j;
						save[j]++;
						break;
					}
				}
			}
			
			for(int j=1;j<p;j++) printf("%d.",save[j]);
			printf("%d\n",save[p]);
		}
	}
}