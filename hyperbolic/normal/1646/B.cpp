#include <stdio.h>
#include <algorithm>

int x[200010];
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
		long long int s1 = x[1]+x[2];
		long long int s2 = x[a];
		
		if(s1<s2)
		{
			printf("YES\n");
			continue;
		}
		
		for(int i=3;;i++)
		{
			if(i>=a+2-i) break;
			s1 += x[i];
			s2 += x[a+2-i];
			if(s1<s2)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}