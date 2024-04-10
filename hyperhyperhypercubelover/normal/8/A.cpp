#include<cstdio>

char a[100001];
char b[100001];
char c[100001];

int main()
{
	int F,B;
    int i,j;
    scanf("%s%s%s",a,b,c);
    F=B=0;
    for(i=0;a[i];i++)
	{
		for(j=0;b[j];j++)if(a[i+j]!=b[j])break;
        if(!b[j])break;
	}
	if(a[i])
	{
		for(i+=j;a[i];i++)
		{
			for(j=0;c[j];j++)if(a[i+j]!=c[j])break;
			if(!c[j])break;
		}
		if(a[i])F=1;
	}
	for(i=0;a[i];i++);
    for(i--;i>=0;i--)
	{
		for(j=0;b[j];j++)if(a[i-j]!=b[j])break;
        if(!b[j])break;
	}
	if(i>=0)
	{
		for(i-=j;i>=0;i--)
		{
			for(j=0;c[j];j++)if(a[i-j]!=c[j])break;
			if(!c[j])break;
		}
		if(i>=0)B=1;
	}
	if(F&&B)puts("both");
	else if(F)puts("forward");
	else if(B)puts("backward");
	else puts("fantasy");
	return 0;
}