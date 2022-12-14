#include <stdio.h>
#define MAX 1234567

int check[10010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=13*48;i++) check[i] = MAX;
	for(int i=0;i<=48;i++)
	{
		for(int j=0;j<=48;j++)
		{
			if(i+j>a) break;
			int s = 4*i+9*j;
			if(check[s]==-1) continue;
			check[s] = check[s]<i+j?check[s]:i+j;
			for(int k=s+49;k<=13*48;k+=49) check[k] = -1;
		}
	}
	
	long long int ans = 0;
	for(int i=0;i<=13*48;i++)
	{
		if(check[i]!=MAX&&check[i]!=-1)
		{
			ans += (a-check[i]+1);
		}
	}
	printf("%lld",ans);
}