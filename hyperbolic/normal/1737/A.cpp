#include <stdio.h>

int count[110];
char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=25;i++) count[i] = 0;
		
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		for(int i=1;i<=b;i++)
		{
			int C = 0, p = 0;
			for(int j=0;C<a/b && j<=25;j++)
			{
				if(count[j]>0&&C<a/b)
				{
					count[j]--;
					p++, C++;
				}
				else break;
			}
			
			printf("%c",'a'+p);
		}
		printf("\n");
	}
}