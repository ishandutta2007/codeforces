#include <stdio.h>

long long int a;
int b;
long long int MAX = 1;
long long int ans,save;
int check[20];
long long int digit[20];
void func(int s, int t)
{
	if(t>b) return;
	if(s==0)
	{
		ans = ans<save?ans:save;
		return;
	}
	for(int i=9;i>=0;i--)
	{
		if(i>check[s])
		{
			long long int k = save + digit[s]*i;
			if(t+i<=b) ans = ans<k?ans:k;
		}
		else if(i==check[s])
		{
			save += digit[s]*i;
			t += i;
			func(s-1,t);
		}
		else break;
	}
}
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	digit[1] = 1;
	for(int i=2;i<=18;i++) digit[i] = digit[i-1]*10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = MAX;
		save = 0;
		scanf("%lld%d",&a,&b);
		if(a==MAX)
		{
			printf("0\n");
			continue;
		}
		
		long long int c = a;
		for(int i=1;i<=18;i++) check[i] = c%10, c/=10;
		func(18,0);
		printf("%lld\n",ans-a);
	}
}