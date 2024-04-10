#include <stdio.h>
#include <string.h>

int count[110];
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int j=0;j<=26;j++) count[j] = 0;
		for(int i=1;i<=a;i++) count[x[i]-'a']++;
		
		for(int i=1;i<=a;i++)
		{
			if(count[x[i]-'a']==1)
			{
				for(int j=i;j<=a;j++) printf("%c",x[j]);
				printf("\n");
				break;
			}
			count[x[i]-'a']--;
		}
	}
}