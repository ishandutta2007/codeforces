#include <stdio.h>
#include <string.h>
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		int count1 = 0, count2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='A') count2++;
			else
			{
				if(count2>=1) count2--;
				else count1++;
			}
		}
		printf("%d\n",count2+(count1%2));
	}
}