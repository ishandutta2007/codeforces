#include <stdio.h>
#include <queue>

struct str{
	int size;
	int partition;
	long long int value;
};
bool operator<(str a, str b)
{
	return a.value<b.value;
}
std::priority_queue<str> Q;

long long int func(int s, int t)
{
	long long int c = (s/t);
	long long int d = (s%t);
	long long int e = t-d;
	return e*(c*c) + d*(c+1)*(c+1);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(c>=2) Q.push({c,1,func(c,1)-func(c,2)});
		ans += func(c,1);
	}
	for(int i=a+1;i<=b;i++)
	{
		//printf("%lld!!\n",ans);
		str A = Q.top();
		Q.pop();
		int c = A.size;
		int d = A.partition;
		long long int e = A.value;
		ans -= e;
		if(c>=d+2) Q.push({c,d+1,func(c,d+1)-func(c,d+2)});
	}
	printf("%lld",ans);
}