#include<cstdio>

char s[2000];

int main()
{
	scanf("%s",s);
    if(s[0]>='a'&&s[0]<='z')s[0]+='A'-'a';
    puts(s);
}