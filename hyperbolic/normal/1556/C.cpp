#include <stdio.h>

int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i+=2)
	{
		long long int sum = 0;
		long long int min = -1;
		for(int j=i+1;j<=a;j+=2)
		{
			long long int L = sum+(-min), R = sum+x[i];
			L = L > 1? L : 1;
			R = R < x[j] ? R : x[j];
			if(L<=R) ans += (R-L+1);
			sum -= x[j];
			min = min<sum?min:sum;
			sum += x[j+1];
			min = min<sum?min:sum;
		}
	}
	printf("%lld",ans);
}