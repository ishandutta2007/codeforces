#include <stdio.h>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int C1=0, C2=0;
		int s;
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++)
		{
			if(x[i]%2==1) C1++;
			else C2++;
		}
		
		if(C1==0)
		{
			printf("No\n");
			goto u;
		}
		
		C1--;
		if(C2>=b-1)
		{
			printf("Yes\n");
			goto u;
		}
		
		if((b-1-C2)%2==1)
		{
			if(C2==0) printf("No\n");
			else if(C1>=b-C2) printf("Yes\n");
			else printf("No\n");
		}
		else
		{
			if(C1>=b-1-C2) printf("Yes\n");
			else printf("No\n");
		}
		
		u:;
	}
}