#include <stdio.h>

int x[110],y[110];
int a,sum;
int check[110][10010];

int func(int s, int t)
{
	if(2*t>sum) return 0;
	if(s>a) return t;
	if(check[s][t]!=-1) return check[s][t];
	
	int s1 = func(s+1,t+x[s]);
	int s2 = func(s+1,t+y[s]);
	return check[s][t] = s1>s2?s1:s2;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) for(int j=0;j<=100*a;j++) check[i][j] = -1;
		
		sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		for(int i=1;i<=a;i++) sum += y[i];
		
		long long int sum2 = 0;
		for(int i=1;i<=a;i++) sum2 += x[i]*x[i];
		for(int i=1;i<=a;i++) sum2 += y[i]*y[i];
		sum2 *= (a-2);
		
		int t1 = func(1,0);
		int t2 = sum-t1;
		
		printf("%lld\n",t1*t1+t2*t2+sum2);
	}
}