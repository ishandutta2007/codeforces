#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		long long int S1 = 0, S2 = 0;
		for(int i=a;i>=1;i--)
		{
			if((a-i)%2==0&& x[i]%2==0) S1 += x[i];
			if((a-i)%2==1&& x[i]%2==1) S2 += x[i];
		}
		if(S1>S2) printf("Alice\n");
		else if(S1<S2) printf("Bob\n");
		else printf("Tie\n");
	}
}