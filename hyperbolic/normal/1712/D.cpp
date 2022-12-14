#include <stdio.h>
#include <algorithm>
#define MAX 1000000000

int x[100010];
std::pair<int,int> y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
		std::sort(y+1,y+a+1);
		for(int i=1;i<=b-1;i++) x[y[i].second] = MAX;
		
		int ans = 0;
		int min;
		// case1
		int temp = x[y[b].second];
		x[y[b].second] = MAX;
		min = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<a;i++)
		{
			int val = (x[i]<x[i+1]?x[i]:x[i+1]);
			val = val<2*min?val:2*min;
			ans = ans>val?ans:val;
		}
		x[y[b].second] = temp;
		//case 2
		
		min = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<a;i++)
		{
			if(x[i]>=2*min||x[i+1]>=2*min) ans = ans>2*min?ans:2*min;
			else
			{
				int val = x[i]>x[i+1]?x[i]:x[i+1];
				ans = ans>val?ans:val;
			}
		}
		
		printf("%d\n",ans);
	}
}