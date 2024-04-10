#include <stdio.h>
#include <algorithm>
int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int s1 = 0, s2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]>0) s1+=x[i];
			if(x[i]<0) s2-=x[i];
		}
		if(s1>s2)
		{
			printf("YES\n");
			for(int i=a;i>=1;i--) printf("%d ",x[i]);
			printf("\n");
		}
		else if(s1<s2)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%d ",x[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
}