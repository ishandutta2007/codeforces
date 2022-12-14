#include <stdio.h>
int x[100010],y[100010],ans[100010];
int main()
{
	int a,pivot;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) y[j] = 0;
		y[x[i]]++;
		pivot = x[i];
		ans[pivot]++;
		for(int j=i+1;j<=a;j++)
		{
			y[x[j]]++;
			if(pivot==x[j])
			{
				ans[pivot]++;
			}
			else
			{
				if(y[pivot]<y[x[j]])
				{
					ans[x[j]]++;
					pivot = x[j];
				}
				else if(y[pivot]>y[x[j]])
				{
					ans[pivot]++;
				}
				else
				{
					if(pivot<x[j])
					{
						ans[pivot]++;
					}
					else
					{
						ans[x[j]]++;
						pivot = x[j];
					}
				}
			}
		}
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}