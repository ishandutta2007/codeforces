#include <stdio.h>

int count[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans = a;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		count[c]++;
	}
	
	int S1 = 0 ,S2 = 0;
	for(int i=1;i<=b;i++)
	{
		S1 += (count[i]/2);
		S2 += (count[i]%2);
	}
	
	int C = S2 - ((a+1)/2-S1);
	printf("%d",a-C);
}