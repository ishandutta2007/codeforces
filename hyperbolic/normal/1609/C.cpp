#include <stdio.h>

int check[1000010];
int x[200010];
int main()
{
	for(int i=2;i<=1000000;i++) if(check[i]==0) for(int j=2*i;j<=1000000;j+=i) check[j] = 1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int ans = 0;
		for(int i=1;i<=b;i++)
		{
			int control = 0, s1 = 0, s2 = 0;
			for(int j=i;j<=a;j+=b)
			{
				if(x[j]==1)
				{
					if(control==0) s1++;
					else s2++;
				}
				else if(check[x[j]]==0)
				{
					if(control==0) control = 1;
					else
					{
						ans += (long long int)(s1+1)*(s2+1), ans--;
						s1 = s2, s2 = 0;
						control = 1;
					}
				}
				else
				{
					if(control==1) ans += (long long int)(s1+1)*(s2+1), ans--;
					s1 = 0, s2 = 0;
					control = 0;
				}
			}
			if(control==1) ans += (long long int)(s1+1)*(s2+1), ans--;
		}
		printf("%lld\n",ans);
	}
}