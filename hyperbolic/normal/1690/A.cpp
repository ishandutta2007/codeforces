#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int t = (a+2)/3+1;
		int s1 = t, s2 = t-1, s3 = a-(2*t-1);
		if(s3==0) s2--,s3++;
		printf("%d %d %d\n",s2,s1,s3);
	}
}