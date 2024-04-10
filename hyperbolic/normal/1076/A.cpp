#include <stdio.h>

char x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<a;i++)
	{
		if(x[i]>x[i+1])
		{
			for(int j=1;j<i;j++) printf("%c",x[j]);
			for(int j=i+1;j<=a;j++) printf("%c",x[j]);
			return 0;
		}
	}
	
	for(int i=1;i<a;i++) printf("%c",x[i]);
}