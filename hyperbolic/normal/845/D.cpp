#include <stdio.h>
#include <vector>

std::vector<int> limit;
int main()
{
	int a;
	scanf("%d",&a);
	
	int ans = 0;
	int speed = 0;
	int event = 0;
	
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b==1)
		{
			int c;
			scanf("%d",&c);
			while(!limit.empty() && limit.back()<c)
			{
				ans++;
				limit.pop_back();
			}
			speed = c;
		}
		if(b==2)
		{
			ans += event;
			event = 0;
		}
		if(b==3)
		{
			int c;
			scanf("%d",&c);
			if(c<speed) ans++;
			else limit.push_back(c);
		}
		if(b==4) event = 0;
		if(b==5) limit.clear();
		if(b==6) event++;
	}
	printf("%d",ans);
}