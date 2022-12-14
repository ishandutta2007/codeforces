#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		if((b+c)/2>=d && (2*a-b-c)/2>=e) printf("YES\n");
		else printf("NO\n");
		
	}
}