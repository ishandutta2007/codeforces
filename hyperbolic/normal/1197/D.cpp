#include <stdio.h>

long long int x[300010],sum[300010];
long long int check1[20],check2[20];
int b;
long long int c;
long long int func(int s, int t)
{
	if(s==t) return 0>x[s]-c?0:x[s]-c;
	
	int h = (s+t)/2;
	long long int s1 = func(s,h);
	long long int s2 = func(h+1,t);
	long long int ans = s1>s2?s1:s2;
	
	for(int i=0;i<=b;i++) check1[i] = check2[i] = 0;
	for(int i=h;i>=s;i--)
	{
		int d = (h-i+1);
		check1[d%b] = check1[d%b]>sum[h]-sum[i-1]-c*(d/b)?check1[d%b]:sum[h]-sum[i-1]-c*(d/b);
	}
	for(int i=h+1;i<=t;i++)
	{
		int d = (i-h);
		check2[d%b] = check2[d%b]>sum[i]-sum[h]-c*(d/b)?check2[d%b]:sum[i]-sum[h]-c*(d/b);
	}
	
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			long long int s3;
			if(i+j>b) s3 = check1[i]+check2[j] - 2*c;
			else if(i+j>0) s3 = check1[i]+check2[j]-c;
			else s3 = check1[i]+check2[j];
			ans = ans>s3?ans:s3;
		}
	}
	return ans;
}

int main()
{
	int a;
	scanf("%d%d%lld",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
	printf("%lld",func(1,a));
}