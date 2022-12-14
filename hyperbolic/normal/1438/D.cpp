#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(a%2==0)
	{
		int s = 0;
		for(int i=1;i<=a;i++) s^=x[i];
		if(s!=0)
		{
			printf("NO");
			return 0;
		}
		a--;
	}
	printf("YES\n");
	int count = 0;
	for(int i=2;i<=a;i+=2) count+=2;
	printf("%d\n",count);
	for(int i=2;i<=a;i+=2) printf("1 %d %d\n",i,i+1);
	for(int i=2;i<=a;i+=2) printf("1 %d %d\n",i,i+1);
}