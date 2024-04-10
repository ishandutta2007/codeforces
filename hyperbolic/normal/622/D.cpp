#include <stdio.h>

int ans[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	int count1 = 0, count2 = 0;
	for(int i=a-1;i>=1;i-=2) count1++;
	
	for(int i=1;i<=count1;i++) ans[i] = a-1+(2*i-2*count1);
	for(int i=count1+1;i<=2*count1;i++) ans[i] = a-1+(2*count1+2-2*i);
	ans[2*count1+1] = a;
	
	for(int i=a-2;i>=1;i-=2) count2++;
	for(int i=2*count1+2;i<=2*count1+1+count2;i++) ans[i] = a-2 + (2*i - 4*count1-2-2*count2);	
	ans[2*count1+count2+2] = a;
	for(int i=2*count1+count2+3;i<=2*a;i++) ans[i] = a-2 + (4*count1+2*count2+6-2*i);
	
	for(int i=1;i<=2*a;i++) printf("%d ",ans[i]);
}