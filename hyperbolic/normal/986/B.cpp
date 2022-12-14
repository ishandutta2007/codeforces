#include <stdio.h>

int x[1000010],check[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int p = i;
		int s = 0;
		if(check[p]==0)
		{
			while(check[p]==0) s++, check[p] = 1, p = x[p];
			ans += (s-1);
		}
	}
	if(a%2==0)
	{
		if(ans%2==1) printf("Um_nik");
		else printf("Petr");
	}
	else
	{
		if(ans%2==1) printf("Petr");
		else printf("Um_nik");
	}
}