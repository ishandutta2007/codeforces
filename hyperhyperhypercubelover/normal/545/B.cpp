#include<cstdio>

char a[111111];
char b[111111];
char r[111111];

int main()
{
	int i,t=0;
    scanf("%s%s",a,b);
    for(i=0;a[i];i++)
	{
		if(a[i]==b[i])r[i]=a[i];
		else
		{
			if(t)r[i]=b[i];
			else r[i]=a[i];
			t=!t;
		}
	}
	if(t)puts("impossible");
	else puts(r);
}