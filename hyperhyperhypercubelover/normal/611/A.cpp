#include<cstdio>

char s[22];

int main()
{
	int n;
    scanf("%d%*s%s",&n,s);
    if(s[0]=='w')
	{
		if(n==5||n==6)puts("53");
		else puts("52");
	}
	else
	{
        if(n<=29)puts("12");
        else if(n==30)puts("11");
        else puts("7");
	}
}