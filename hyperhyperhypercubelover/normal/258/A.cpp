#include<cstdio>

char a[100001];

int main()
{
	int i,j,n;
    scanf("%s",a);
    if(!a[1])
	{
		puts("0");
		return 0;
	}
    for(i=0;a[i];i++)if(a[i]=='0')break;
    if(!a[i])
	{
		for(j=1;j<i;j++)putchar('1');
		return 0;
	}
    for(j=0;j<i;j++)putchar('1');
    for(j=i+1;a[j];j++)putchar(a[j]);
}