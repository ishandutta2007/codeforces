#include<cstdio>

int main()
{
	int i,n;
    scanf("%d",&n);
    if(n<4)puts("NO");
    else
	{
		puts("YES");
		if(n%2==0)
		{
			puts("1 * 2 = 2");
			puts("2 * 3 = 6");
			puts("6 * 4 = 24");
			for(i=5;i<n;i+=2)printf("%d - %d = 1\n",i+1,i);
			for(i=0;i<(n-4)/2;i++)printf("24 * 1 = 24\n");
		}
		else
		{
			puts("4 * 5 = 20");
			puts("20 + 3 = 23");
			puts("23 + 2 = 25");
			puts("25 - 1 = 24");
			for(i=6;i<n;i+=2)printf("%d - %d = 1\n",i+1,i);
			for(i=0;i<(n-5)/2;i++)printf("24 * 1 = 24\n");
		}
	}
}