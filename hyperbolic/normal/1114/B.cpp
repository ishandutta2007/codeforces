#include <stdio.h>
#include <algorithm>

struct str{
	int x0;
	int y0;
	int check;
}x[200010];

bool cmp1(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.y0<b.y0;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		x[i].x0 = d;
		x[i].y0 = i;
		x[i].check = 0;
	}
	std::sort(x+1,x+a+1,cmp1);
	
	long long int sum = 0;
	for(int i=a-(b*c)+1;i<=a;i++)
	{
		sum += x[i].x0;
		x[i].check = 1;
	}
	std::sort(x+1,x+a+1,cmp2);
	printf("%lld\n",sum);
	int p = 1;
	int s = 0;
	for(int i=1;i<c;i++)
	{
		while(1)
		{
			s += x[p].check;
			if(s==b)
			{
				printf("%d ",p);
				s = 0;
				break;
			}
			p++;
		}
		p++;
	}
}