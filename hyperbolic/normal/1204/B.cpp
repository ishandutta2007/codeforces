#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	long long int min = 0, max = 0;
	for(int i=1;i<=c;i++) max += (1<<(i-1));
	for(int i=c+1;i<=a;i++) max += (1<<(c-1));
	for(int i=1;i<=b;i++) min += (1<<(i-1));
	for(int i=b+1;i<=a;i++) min ++;
	printf("%lld %lld",min,max);
}