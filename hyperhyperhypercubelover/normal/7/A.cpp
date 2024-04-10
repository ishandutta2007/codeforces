#include<cstdio>

char s[10];
int a[8];
int b[8];

int main()
{
	int res=0;
    int i,j;
    for(i=0;i<8;i++)
	{
		scanf("%s",s);
		for(j=0;j<8;j++)if(s[j]=='B')
		{
			a[i]++;
			b[j]++;
		}
	}
	for(i=0;i<8;i++)
	{
		if(a[i]==8)res++;
		if(b[i]==8)res++;
	}
	printf("%d",res==16?8:res);
}