#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int p = 0;
	int even,odd;
	for(int i=1;i<=a;i++)
	{
		if((x[i]+100000)%2==1)
		{
			p = i;
			even = 0;
			odd = x[i];
			break;
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(i==p) continue;
		if((x[i]+100000)%2==1)
		{
			int even2 = even>odd+x[i]?even:odd+x[i];
			int odd2 = x[i]>even+x[i]?x[i]:even+x[i];
			odd2 = odd2>odd?odd2:odd;
			even = even2;
			odd = odd2;
		}
		else
		{
			int even2 = even>even+x[i]?even:even+x[i];
			even2 = even2>x[i]?even2:x[i];
			int odd2 = odd>odd+x[i]?odd:odd+x[i];
			odd = odd2;
			even = even2;
		}
	}
	printf("%d",odd);
}