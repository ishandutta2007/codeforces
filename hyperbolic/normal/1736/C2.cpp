#include <stdio.h>
#include <vector>

std::vector<int> event[200010];
int x[200010];
long long int sum1[200010],sum2[200010],value1[200010],value2[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		int start = i-x[i];
		if(start>=1) event[start].push_back(i);
	}
	
	int limit1 = a+1;
	int limit2 = a+1;
	for(int i=a;i>=1;i--)
	{
		for(int j=0;j<event[i].size();j++)
		{
			if(limit1>=event[i][j])
			{
				limit2 = limit1;
				limit1 = event[i][j];
			}
			else if(limit2>=event[i][j]) limit2 = event[i][j];
		}
		value1[i] = limit1;
		value2[i] = limit2;
	}
	for(int i=1;i<=a;i++) sum1[i] = sum1[i-1] + value1[i];
	for(int i=1;i<=a;i++) sum2[i] = sum2[i-1] + value2[i];
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		
		if(x[c]<d)
		{
			int R = c-x[c]>0?c-x[c]:0;
			int L = c-d+1>1?c-d+1:1;
			
			int p1, p2;
			int min, max;
			
			p1 = R;
			p2 = -1;
			min = L, max = R;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(value1[h]>=c)
				{
					p2 = h;
					max = h-1;
				}
				else min = h+1;
			}
			
			long long int sum = 0;
			if(p2==-1) sum = sum1[a]-sum1[0];
			else sum = (sum1[p2-1]-sum1[0]) + (sum2[p1]-sum2[p2-1]) + (sum1[a]-sum1[p1]);
			printf("%lld\n",sum-(long long int)a*(a+1)/2);
		}
		else
		{
			int L = c-x[c]+1>1?c-x[c]+1:1;
			int R = c-d>0?c-d:0;
			
			int p1, p2;
			int min, max;
			
			p1 = R;
			p2 = -1;
			min = L, max = R;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(value1[h]>=c)
				{
					p2 = h;
					max = h-1;
				}
				else min = h+1;
			}
			
			long long int sum = 0;
			if(p2==-1) sum = sum1[a]-sum1[0];
			else sum = (sum1[p2-1]-sum1[0]) + (long long int)c*(p1-p2+1) + (sum1[a]-sum1[p1]);
			printf("%lld\n",sum-(long long int)a*(a+1)/2);
		}
	}
}