#include <stdio.h>
#include <vector>

std::vector<long long int> ans;
long long int x[300010],y[300010];
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	scanf("%d",&b);
	for(int i=1;i<=b;i++) scanf("%lld",&y[i]);
	
	int p1 = 1, p2 = 1;
	while(p1<=a||p2<=b)
	{
		if(p1>a)
		{
			printf("-1");
			return 0;
		}
		if(p2>b)
		{
			printf("-1");
			return 0;
		}
		
		if(x[p1]==y[p2])
		{
			ans.push_back(x[p1]);
			p1++,p2++;
		}
		else
		{
			if(x[p1]<y[p2])
			{
				if(p1==a)
				{
					printf("-1");
					return 0;
				}
				x[p1+1] += x[p1];
				p1++;
			}
			else
			{
				if(p2==b)
				{
					printf("-1");
					return 0;
				}
				y[p2+1] += y[p2];
				p2++;
			}
		}
	}
	printf("%d",ans.size());
}