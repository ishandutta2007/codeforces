#include <stdio.h>
#include <algorithm>

int abs(int k)
{
	return k>0?k:-k;
}
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a/2;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+(a/2)+1);
	
	int count1 = 0, count2 = 0;
	for(int i=1;i<=a/2;i++) count1 += abs(2*i-x[i]);
	for(int i=1;i<=a/2;i++) count2 += abs(x[i]-(2*i-1));
	printf("%d",count1<count2?count1:count2);
}