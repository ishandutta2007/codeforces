#include <stdio.h>
#include <set>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int getQuery(int a, int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int k;
	scanf("%d",&k);
	return k;
}

int x[10],ans[10];
int main()
{
	x[1] = getQuery(1,2);
	x[2] = getQuery(1,3);
	x[3] = getQuery(1,4);
	x[4] = getQuery(1,5);
	int g = gcd(x[1],x[2]);
	g = gcd(g,x[3]);
	g = gcd(g,x[4]);
	g = gcd(g,x[5]);
	while(1)
	{
		ans[1] = g;
		for(int i=2;i<=5;i++) ans[i] = x[i-1]/g;
		
		std::set<int> S;
		S.insert(4);
		S.insert(8);
		S.insert(15);
		S.insert(16);
		S.insert(23);
		S.insert(42);
		for(int i=1;i<=5;i++) S.erase(ans[i]);
		
		if(S.size()==1)
		{
			printf("! ");
			for(int i=1;i<=5;i++) printf("%d ",ans[i]);
			printf("%d",*(S.begin()));
			fflush(stdout);
			return 0;
		}
		g/=2;
	}
}