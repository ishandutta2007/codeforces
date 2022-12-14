#include <stdio.h>

char x[100010];
int count[30];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	if(a==1)
	{
		printf("Yes");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		count[x[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(count[i]>=2)
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}