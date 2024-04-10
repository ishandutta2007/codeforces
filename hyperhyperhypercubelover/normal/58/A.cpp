#include<cstdio>

char s[111];

int main()
{
    int i;
    scanf("%s",s);
    for(i=0;s[i]&&s[i]!='h';i++);
    if(!s[i])
	{
		puts("NO");
		return 0;
	}
    for(i++;s[i]&&s[i]!='e';i++);
    if(!s[i])
	{
		puts("NO");
		return 0;
	}
    for(i++;s[i]&&s[i]!='l';i++);
    if(!s[i])
	{
		puts("NO");
		return 0;
	}
    for(i++;s[i]&&s[i]!='l';i++);
    if(!s[i])
	{
		puts("NO");
		return 0;
	}
    for(i++;s[i]&&s[i]!='o';i++);
    if(!s[i])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
}