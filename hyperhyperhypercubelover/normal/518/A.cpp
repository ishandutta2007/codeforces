#include<cstdio>
#include<cstring>

char a[200];
char b[200];

int main()
{
	int i,j;
	scanf("%s%s",a,b);
	for(i=0;a[i];i++);
	i--;
    while(i>=0&&a[i]=='z')i--;
    a[i]++;
    while(a[++i])a[i]='a';
    if(strcmp(a,b))puts(a);
    else puts("No such string");
	return 0;
}