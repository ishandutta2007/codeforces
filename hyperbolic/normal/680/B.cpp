#include <stdio.h>
int x[100010];
int main()
{
	int a,b,count=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(x[b]==1) count++;
	for(int i=1;i<=a;i++)
	{
		int s1,s2,count1,count2;
		if(b-i>=1) s1=x[b-i],count1 = 1;
		else s1=0,count1 = 0;
		if(b+i<=a) s2=x[b+i],count2 = 1;
		else s2=0,count2 = 0;
		
		if(s1+s2==count1+count2) count+=count1+count2;
	}
	printf("%d",count);
}