#include<stdio.h>
#include<string.h>
int main()
{
	char x[101],y[101];
	scanf("%s%s",x,y);
	int len=strlen(x),flag=0;
	for(int i=0;i<len;i++)
	{
		if(x[i]<y[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("-1");
	else
	printf("%s",y);
}