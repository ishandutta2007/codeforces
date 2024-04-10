#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(c==1&&d==a) printf("0");
	else if(c==1) printf("%d",abs(b-d)+1);
	else if(d==a) printf("%d",abs(b-c)+1);
	else
	{
		int s1 = abs(b-d) + 1 + abs(c-d) + 1;
		int s2 = abs(b-c) + 1 + abs(d-c) + 1;
		printf("%d",s1<s2?s1:s2);
	}
}