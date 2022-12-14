#include <stdio.h>

int size[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int p = 0;
		size[0] = 1;
		for(int i=1;;i++)
		{
			if((1<<(i+1))-1 > a)
			{
				size[i] = a - ((1<<i)-1);
				p = i;
				break;
			}
			else size[i] = (1<<i);
		}
		
		long long int ans = 1;
		for(int i=0;i<=p;i++) ans *= (size[i]+1), ans%=b;
		printf("%lld\n",(ans+b-1)%b);
	}
}