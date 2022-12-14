#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		
		long long int sum = 0;
		long long int S = 1;
		for(int p=0;;p++)
		{
			if(sum+3*S<a) sum+=3*S;
			else
			{
				long long int start = S;
				long long int s = start + (a-sum-1)/3;
				long long int t = (a-sum-1)%3; // 0 1 2
				//printf("%lld %lld\n",s,t);
				
				long long int s2 = 0;
				long long int k = s;
				long long int d = 1;
				while(k)
				{
					if(k%4==1) s2 += d*2;
					else if(k%4==2) s2 += d*3;
					else if(k%4==3) s2 += d*1;
					k/=4;
					d*=4;
				}
				
				if(t==0) printf("%lld\n",s);
				else if(t==1) printf("%lld\n",s2);
				else printf("%lld\n",s^s2);
				break;
			}
			S*=4;
		}
	}
}