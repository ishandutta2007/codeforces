#include <stdio.h>
#include <string.h>

char x[100010];
long long int power[110];
int main()
{
	power[0] = 1;
	for(int i=1;i<=60;i++) power[i] = power[i-1]*2;
	
	long long int a;
	int b;
	scanf("%lld%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		scanf("%s",x+1);
		int d = strlen(x+1);
		
		int p = 0;
		for(int j=0;j<=60;j++)
		{
			if((c/power[j])%2==1)
			{
				p = j;
				break;
			}
		}
		
		for(int j=1;j<=d;j++)
		{
			if(x[j]=='U')
			{
				if(((power[p]+c)/power[p+1])%2==1)
				{
					long long int c2 = power[p]+c;
					if(c2<=a) c = c2, p++;
				}
				else c = c-power[p],p++;
			}
			else if(x[j]=='L')
			{
				if(p==0) continue;
				c -= power[p-1], p--;
			}
			else
			{
				if(p==0) continue;
				c += power[p-1], p--;
			}
		}
		printf("%lld\n",c);
	}
}