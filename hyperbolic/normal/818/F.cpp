#include <Stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		if(a==1)
		{
			printf("0\n");
			continue;
		}
		
		long long int min = 1, max = a;
		long long int pivot = 0;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int C = (long long int)(a-h)*(a-h-1)/2;
			if(C>=h)
			{
				pivot = h;
				min = h+1;
			}
			else max = h-1;
		}
		
		long long int ans = 0;
		long long int C1 = (long long int)(a-pivot)*(a-pivot-1) + pivot;
		long long int C2 = (long long int)(a-pivot-1)*(a-pivot-2)/2 + pivot + 1;
		if(C1>2*pivot) C1 = 2*pivot;
		if(C2>2*(pivot+1)) C2 = 2*(pivot+1);
		ans = ans>C1?ans:C1;
		ans = ans>C2?ans:C2;
		printf("%lld\n",ans);
	}
}