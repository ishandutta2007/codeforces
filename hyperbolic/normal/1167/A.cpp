#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int p = a+1;
		for(int i=a;i>=1;i--) if(x[i]=='8') p = i;
		if(a-p+1>=11) printf("YES\n");
		else printf("NO\n");
	}
}