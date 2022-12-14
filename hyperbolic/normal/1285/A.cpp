#include <stdio.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int count1 = 0 ,count2 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='L') count1++;
		else count2++;
	}
	printf("%d",count1+count2+1);
}