#include <stdio.h>
#include <queue>
#define SIZE 450
#define MAX 1234567890

int x[100010];
long long int sum[100010];
long long int value[510];

std::queue<long long int> event[510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		
		value[0] = MAX;
		for(int j=1;j<=SIZE;j++) value[j] = 0;
		for(int i=a;i>=1;i--)
		{
			for(int j=SIZE;j>=1;j--)
			{
				// i ~ i+j-1
				if(i+j-1>a) continue;
				if(sum[i+j-1]-sum[i-1] < value[j-1]) event[j].push(sum[i+j-1]-sum[i-1]);
				else event[j].push(0);
			}
			
			for(int j=SIZE;j>=1;j--)
			{
				while(event[j].size()>j)
				{
					value[j] = value[j]>event[j].front()?value[j]:event[j].front();
					event[j].pop();
				}
			}
		}
		
		for(int j=SIZE;j>=1;j--)
		{
			while(event[j].size()>0)
			{
				value[j] = value[j]>event[j].front()?value[j]:event[j].front();
				event[j].pop();
			}
		}
		
		int ans = 0;
		for(int j=0;j<=SIZE;j++) if(value[j]!=0) ans = j;
		printf("%d\n",ans);
	}
}