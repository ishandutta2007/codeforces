#include <stdio.h>

long long int x[200010],y[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<a;i++) scanf("%lld",&y[i]);
		for(int i=2;i<=a;i++) x[i] = x[i]>x[i-1]?x[i]:x[i-1];
		
		long long int S = 0;
		long long int T = 0;
		long long int ans = 1234567890;
		if(b%x[1]==0) ans = b/x[1];
		else ans = b/x[1] + 1;
		
		for(int i=2;i<=a;i++)
		{
			if(S>=y[i-1]) T++,S-= y[i-1];
			else
			{
				long long int n;
				if((y[i-1]-S)%x[i-1]==0) n = (y[i-1]-S)/x[i-1];
				else n = (y[i-1]-S)/x[i-1] + 1;
				
				T += (n+1);
				S = S + n*x[i-1] - y[i-1];
			}
			if(S>=b) ans = ans<T?ans:T;
			else
			{
				long long int m;
				if((b-S)%x[i]==0) m = (b-S)/x[i];
				else m = (b-S)/x[i] + 1;
				ans = ans<T+m?ans:T+m;
			}
		}
		
		printf("%lld\n",ans);
	}
}