#include <stdio.h>

int check[5][100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int count = 0;
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(check[c][d]==0)
		{
			if(check[3-c][d-1]==1) count++;
			if(check[3-c][d]==1) count++;
			if(check[3-c][d+1]==1) count++;
			check[c][d] = 1;
			
			if(count>0) printf("No\n");
			else printf("Yes\n");
		}
		else
		{
			if(check[3-c][d-1]==1) count--;
			if(check[3-c][d]==1) count--;
			if(check[3-c][d+1]==1) count--;
			check[c][d] = 0;
			
			if(count>0) printf("No\n");
			else printf("Yes\n");
		}
	}
}