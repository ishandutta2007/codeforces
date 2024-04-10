#include<cstdio>
#include<cstring>

char s[111];
char t[111]="CODEFORCES";

int main()
{
	int i,j,n;
	scanf("%s",s);
	n=strlen(s);
	if(n<11)
	{
		puts("NO");
		return 0;
	}
	for(i=0;i<10;i++)if(s[i]!=t[i])break;
    for(;i<10;i++)if(s[n+i-10]!=t[i])break;
    puts(i<10?"NO":"YES");
	return 0;
}