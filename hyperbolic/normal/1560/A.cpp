#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	for(int i=1;i<=100000;i++)
	{
		if(i%10==3) continue;
		int t = i;
		int sum = 0;
		while(t)
		{
			sum += (t%10);
			t/=10;
		}
		if(sum%3!=0) V.push_back(i);
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",V[a-1]);
	}
}