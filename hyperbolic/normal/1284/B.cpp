#include <stdio.h>

int x[100010];
int max[100010],min[100010],check[100010];
int count[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++) scanf("%d",&x[j]);
		max[i] = x[b];
		min[i] = x[b];
		for(int j=b-1;j>=1;j--)
		{
			if(x[j]<max[i]) check[i] = 1;
			max[i] = max[i]>x[j]?max[i]:x[j];
			min[i] = min[i]<x[j]?min[i]:x[j];
		}
	}
	for(int i=1;i<=a;i++) if(check[i]==0) count[max[i]]++;
	for(int i=1;i<=1000000;i++) count[i] += count[i-1];
	
	long long int S = 0;
	for(int i=1;i<=a;i++) S += check[i];
	long long int ans = S*a + a*S - S*S;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) continue;
		ans += (count[1000000] - count[min[i]]);
	}
	printf("%lld",ans);
}