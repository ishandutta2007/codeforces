#include <stdio.h>
int x[300010];
int main()
{
	int a,b,i,s;
	scanf("%d%d",&a,&b);
	for(i=1;i<a;i++) scanf("%d",&x[i]);
	s=1;
	while(1)
	{
		s=s+x[s];
		if(s==b)
		{
			printf("YES");
			return 0;
		}
		if(s>=a)
		{
			printf("NO");
			return 0;
		}
	}
}