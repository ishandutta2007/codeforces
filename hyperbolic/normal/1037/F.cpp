#include <stdio.h>
#define MOD 1000000007
#define MAX 1234567890

int x[1000010];
long long int y[1000010];
int b;
long long int func(int s, int t)
{
	if(s>=t) return 0;
	int h = (s+t)/2;
	y[h] = x[h],y[h+1] = x[h+1];
	for(int i=h-1;i>=s;i--) y[i] = x[i]>y[i+1]?x[i]:y[i+1];
	for(int i=h+2;i<=t;i++) y[i] = x[i]>y[i-1]?x[i]:y[i-1];
	y[s-1] = y[t+1] = MAX;
	
	long long int ans = 0;
	
	int p = h+1;
	int start = h+b;
	for(int i=h;i>=s;i--)
	{
		while(1)
		{
			if(y[i]<y[p]) break;
			else p++;
		}
		//p-1
		start--;
		if(start<=h) start += (b-1);
		if(start>p-1) continue;
		else
		{
			int k = (p-1)-(start);
			ans += (y[i]*((k/(b-1))+1));
			ans %= MOD;
		}
	}
	
	p = h;
	start = h-b+1;
	for(int i=h+1;i<=t;i++)
	{
		while(1)
		{
			if(y[i]<=y[p]) break;
			else p--;
		}
		//p-1
		start++;
		if(start>=h+1) start -= (b-1);
		if(start<(p+1)) continue;
		else
		{
			int k = (start)-(p+1);
			ans += (y[i]*((k/(b-1))+1));
			ans %= MOD;
		}
	}
	return (ans + func(s,h) + func(h+1,t))%MOD;
}
int main()
{
	int a;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("%lld",func(1,a));
}