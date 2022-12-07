#include<stdio.h>
#include<string.h>
int main()
{
	char s[4][11];
	scanf("%s%s",s[0],s[1]);
	printf("%s %s\n",s[0],s[1]);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%s",s[2],s[3]);
		if(strcmp(s[0],s[2])==0)
		strcpy(s[0],s[3]);
		else
		strcpy(s[1],s[3]);
		printf("%s %s\n",s[0],s[1]);
	}
}