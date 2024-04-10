#include<cstdio>

char s[111111];

int main()
{
	int i;
	scanf("%s",s);
	for(i=0;s[i];i++)if(s[i]=='A'&&s[i+1]=='B')break;
    for(i+=2;s[i];i++)if(s[i]=='B'&&s[i+1]=='A')break;
    if(s[i])
	{
		printf("YES");
		return 0;
	}
	for(i=0;s[i];i++)if(s[i]=='B'&&s[i+1]=='A')break;
    for(i+=2;s[i];i++)if(s[i]=='A'&&s[i+1]=='B')break;
    if(s[i])
	{
		printf("YES");
		return 0;
	}
	printf("NO");
}