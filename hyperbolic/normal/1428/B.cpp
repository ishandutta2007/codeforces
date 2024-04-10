#include <stdio.h>

char x[300010];
int check[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x);
		int control1 = 0, control2 = 0;
		for(int i=0;i<a;i++)
		{
			if(x[i]=='>') control1 = 1;
			if(x[i]=='<') control2 = 1;
		}
		if(control1==1&&control2==1)
		{
			for(int i=0;i<a;i++) check[i] = 0;
			for(int i=0;i<a;i++)
			{
				if(x[i]=='-')
				{
					check[(i+1)%a] = 1;
					check[i] = 1;
				}
			}
			int sum = 0;
			for(int i=0;i<a;i++) sum += check[i];
			printf("%d\n",sum);
		}
		else printf("%d\n",a);
	}
}