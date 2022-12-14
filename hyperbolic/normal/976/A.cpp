#include <stdio.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int count = 0;
	for(int i=1;i<=a;i++) count += (x[i]-'0');
	int count2 = a-count;
	if(count==0)
	{
		printf("0");
		return 0;
	}
	
	printf("1");
	for(int i=1;i<=count2;i++) printf("0");
}