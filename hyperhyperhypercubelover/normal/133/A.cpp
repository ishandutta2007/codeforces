#include<cstdio>

char s[200];

int main()
{
	int i;
	scanf("%s",s);
	for(i=0;s[i];i++)if(s[i]=='H'||s[i]=='Q'||s[i]=='9')
	{
		puts("YES");
		return 0;
	}
	puts("NO");
}