#include <stdio.h>
#include <algorithm>
#define MAX 1000000

int value[4000010];

int getMax(int L, int R)
{
	L += (1048576-1);
	R += (1048576-1);
	int ans = 0;
	while(L<=R)
	{
		if(L%2==1) ans = ans>value[L]?ans:value[L],L++;
		if(R%2==0) ans = ans>value[R]?ans:value[R],R--;
		L/=2,R/=2;
	}
	return ans;
}

int x[200010];
int main()
{
	int C = 1048576;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int ans = 0;
	for(int i=a;i>=1;i--)
	{
		if(x[i]==x[i+1]) continue;
		for(int j=x[i];j<=MAX;j+=x[i])
		{
			int L = j;
			int R = L+x[i]-1;
			if(R>MAX) R = MAX;
			
			int t = getMax(L,R) - j;
			ans = ans>t?ans:t;
		}
		
		value[C+x[i]-1] = x[i];
		int t = (C+x[i]-1)/2;
		while(t)
		{
			value[t] = value[2*t]>value[2*t+1]?value[2*t]:value[2*t+1];
			t/=2;
		}
	}
	printf("%d",ans);
}