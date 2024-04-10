#include<cstdio>

char s[200];
int a[200];

int main()
{
	int i,r=0;
	scanf("%s",s);
	for(i=0;s[i];i++)a[s[i]]=1;
	for(i=0;i<200;i++)r+=a[i];
	puts(r%2?"IGNORE HIM!":"CHAT WITH HER!");
}