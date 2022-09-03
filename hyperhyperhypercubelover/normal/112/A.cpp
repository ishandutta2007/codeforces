#include<stdio.h>
#include<string.h>

char a[200];
char b[200];

int main()
{
    int i,n;
    scanf("%s%s",a,b);
    n=strlen(a);
    for(i=0;i<n;i++)if((a[i]>='A')&&(a[i]<='Z'))a[i]+='a'-'A';
    n=strlen(b);
    for(i=0;i<n;i++)if((b[i]>='A')&&(b[i]<='Z'))b[i]+='a'-'A';
    printf("%d",strcmp(a,b));
}