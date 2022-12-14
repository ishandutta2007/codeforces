#include <stdio.h>

long long int MAX = 1;
int main()
{
	for(int i=1;i<=17;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		
		int l = (l1>l2)?l1:l2;
		int r = (r1<r2)?r1:r2;
		int L = (l1<l2)?l1:l2;
		int R = (r1>r2)?r1:r2;
		
		long long int k = (r-l);
		long long int s = 0;
		if(k<0)
		{
			s = (-k);
			k = 0;
		}
		long long int t = (R-L)-k;
		
		long long int ans = MAX;
		for(int i=1;i<=a;i++)
		{
			if(k*i>=b) ans = 0;
			else
			{
				if(k*i+t*i>=b) ans = ans<s*i+(b-k*i)?ans:s*i+(b-k*i);
				else ans = ans<s*i+t*i+(b-k*i-t*i)*2?ans:s*i+t*i+(b-k*i-t*i)*2;
			}
		}
		printf("%lld\n",ans);
	}
}