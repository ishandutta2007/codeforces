#include <stdio.h>

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
		int left = x[1]-1, right = x[1]+1;
		for(int i=2;i<=a;i++)
		{
			left++;
			right++;
			if(right<x[i]-1)
			{
				printf("NO\n");
				goto u;
			}
			left = left>x[i]-1?left:x[i]-1;
			right = right<x[i]+1?right:x[i]+1;
		}
		printf("YES\n");
		u:;
	}
}