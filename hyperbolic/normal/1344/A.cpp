#include <stdio.h>
#include <algorithm>

int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = (((x[i]%a) + a)%a + i)%a;
		std::sort(y+1,y+a+1);
		for(int i=1;i<a;i++)
		{
			if(y[i]==y[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}