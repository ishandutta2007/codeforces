#include <stdio.h>

int check[10],check2[10];
int x[1000010];
int main()
{
	for(int i=0;i<1000000;i++)
	{
		check[0] = i%10;
		check[1] = (i/10)%10;
		check[2] = (i/100)%10;
		check[3] = (i/1000)%10;
		check[4] = (i/10000)%10;
		check[5] = (i/100000)%10;
		if(check[0]+check[1]+check[2]==check[3]+check[4]+check[5]) x[i] = 1;
	}
	
	int a;
	scanf("%d",&a);
	check2[0] = a%10;
	check2[1] = (a/10)%10;
	check2[2] = (a/100)%10;
	check2[3] = (a/1000)%10;
	check2[4] = (a/10000)%10;
	check2[5] = (a/100000)%10;
	int ans = 6;
	for(int i=0;i<1000000;i++)
	{
		if(x[i]==1)
		{
			check[0] = i%10;
			check[1] = (i/10)%10;
			check[2] = (i/100)%10;
			check[3] = (i/1000)%10;
			check[4] = (i/10000)%10;
			check[5] = (i/100000)%10;
			
			int count = 0;
			for(int j=0;j<=5;j++) if(check[j]!=check2[j]) count++;
			ans = ans<count?ans:count;
		}
	}
	printf("%d",ans);
}