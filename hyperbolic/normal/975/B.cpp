#include <stdio.h>

int x[110],y[110];
int main()
{
	for(int i=0;i<14;i++) scanf("%d",&x[i]);
	long long int ans = 0;
	for(int i=0;i<14;i++)
	{
		for(int j=i;j<14+i;j++) y[j] = x[j%14];
		int d = x[i]/14;
		int r = x[i]%14;
		y[i] = 0;
		for(int j=i;j<14+i;j++) y[j] += d;
		for(int j=i+1;j<=i+r;j++) y[j]++;
		long long int sum = 0;
		for(int j=i;j<14+i;j++) if(y[j]%2==0) sum += y[j];
		ans = ans>sum?ans:sum;
	}
	printf("%lld",ans);
}