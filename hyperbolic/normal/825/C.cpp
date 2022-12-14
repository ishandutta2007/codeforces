#include <stdio.h>
#include <algorithm>

int x[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		while(1)
		{
			if(b>x[i]) break;
			else if(2*b>=x[i])
			{
				b = x[i];
				break;
			}
			else
			{
				ans++;
				b*=2;
			}
		}
	}
	printf("%d",ans);
}