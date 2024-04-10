#include<cstdio>

char s[200];

int main()
{
	int i,j;
	scanf("%s",s);
    for(i=0;s[i];i+=2)for(j=i;s[j];j+=2)if(s[i]>s[j])s[i]^=s[j]^=s[i]^=s[j];
    puts(s);
}