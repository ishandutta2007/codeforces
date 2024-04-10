#include <stdio.h>

int main()
{
	int a,b,c,s=0,max=0,control=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		control = 0;
		for(int j=1;j<=a;j++)
		{
			scanf("%1d",&c);
			if(c==0) control = 1;
		}
		if(control) s++;
		else s=0;
		max = max>s?max:s;
	}
	printf("%d",max);
}