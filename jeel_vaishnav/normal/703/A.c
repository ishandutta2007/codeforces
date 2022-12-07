#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int count_a=0,count_b=0,a,b;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
		count_a++;
		else if(b>a)
		count_b++;
	}
	if(count_a>count_b)
	printf("Mishka");
	else if(count_b>count_a)
	printf("Chris");
	else 
	printf("Friendship is magic!^^");
}