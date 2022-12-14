#include <stdio.h>

int ans[100010];
int main()
{
	int a,b;
	scanf("%d",&a);
	for(b=1;b*b<=a;b++);
	b--;
	int p = a;
	int s = 0;
	while(1)
	{
		if(p-b+1>=1)
		{
			for(int i=p-b+1;i<=p;i++) ans[i] = s + (i-p+b);
			s += b;
			p -= b;
		}
		else
		{
			for(int i=1;i<=p;i++) ans[i] = s + i;
			break;
		}
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}