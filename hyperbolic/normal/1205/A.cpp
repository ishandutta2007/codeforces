#include <stdio.h>

int ans[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	if(a%2==0) printf("NO");
	else
	{
		printf("YES\n");
		for(int i=1;i<=a;i+=2) ans[i] = 2*i-1, ans[i+a] = 2*i;
		for(int i=2;i<=a;i+=2) ans[i] = 2*i, ans[i+a] = 2*i-1;
		for(int i=1;i<=2*a;i++) printf("%d ",ans[i]);
	}
}