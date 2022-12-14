#include <stdio.h>
#include <algorithm>
int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int s=0;
	for(int i=1;i<a;i++) s+=x[i];
	printf("%I64d",x[a]-s<=0?1:x[a]-s+1);
}