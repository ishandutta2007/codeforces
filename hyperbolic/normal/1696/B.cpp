#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int control = 0;
		for(int i=1;i<=a;i++) if(x[i]!=0) control = 1;
		if(control==0) printf("0\n");
		else
		{
			int L,R;
			for(int i=1;i<=a;i++)
			{
				if(x[i]!=0)
				{
					L = i;
					break;
				}
			}
			for(int i=a;i>=1;i--)
			{
				if(x[i]!=0)
				{
					R = i;
					break;
				}
			}
			
			control = 0;
			for(int i=L;i<=R;i++) if(x[i]==0) control = 1;
			if(control==0) printf("1\n");
			else printf("2\n");
		}
	}
}