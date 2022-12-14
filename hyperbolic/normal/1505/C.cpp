#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	long long int sum = 0;
	for(int i=3;i<=a;i++)
	{
		if((x[i]-'A')!=((x[i-1]-'A')+(x[i-2]-'A'))%26)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}