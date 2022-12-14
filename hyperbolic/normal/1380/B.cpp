#include <stdio.h>
#include <string.h>
char x[200010];
int count[5];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[1] = count[2] = count[3] = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='R') count[1]++;
			if(x[i]=='S') count[2]++;
			if(x[i]=='P') count[3]++;
		}
		
		int max = 0;
		for(int i=1;i<=3;i++) max = max>count[i]?max:count[i];
		if(max==count[1]) for(int i=1;i<=a;i++) printf("%c",'P');
		else if(max==count[2]) for(int i=1;i<=a;i++) printf("%c",'R');
		else for(int i=1;i<=a;i++) printf("%c",'S');
		printf("\n");
	}
}