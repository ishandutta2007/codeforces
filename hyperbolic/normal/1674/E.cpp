#include <stdio.h>
#include <algorithm>

int x[200010],y[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = x[i];
	std::sort(y+1,y+a+1);
	
	int ans = (y[1]+1)/2 + (y[2]+1)/2;
	
	for(int i=1;i<a;i++)
	{
		if(x[i]>2*x[i+1])
		{
			int c = (x[i]+1)/2;
			ans = ans<c?ans:c;
		}
		else if(x[i+1]>2*x[i])
		{
			int c = (x[i+1]+1)/2;
			ans = ans<c?ans:c;
		}
		else
		{
			int c = (x[i]+x[i+1]+2)/3;
			ans = ans<c?ans:c;
		}
	}
	
	for(int i=1;i<=a-2;i++)
	{
		int c = (x[i]+x[i+2]+1)/2;
		ans = ans<c?ans:c;
	}
	
	printf("%d\n",ans);
}