#include <stdio.h>
#include <queue>
#define MOD 998244353
struct str{
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}

int x[200010];
int check[200010];
std::priority_queue<str> Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) Q.push({x[i],i});
	
	long long int ans1 = 0;
	while(b--)
	{
		int v = Q.top().x0;
		int index = Q.top().y0;
		Q.pop();
		check[index] = 1;
		ans1 += v;
	}
	
	int L,R;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1)
		{
			L = i;
			break;
		}
	}
	for(int i=a;i>=1;i--)
	{
		if(check[i]==1)
		{
			R = i;
			break;
		}
	}
	
	long long int ans2 = 1;
	int S = 0;
	for(int i=L;i<=R;i++)
	{
		if(check[i]==1)
		{
			ans2 *= (S+1);
			ans2 %= MOD;
			S = 0;
		}
		else S++;
	}
	printf("%lld %lld",ans1,ans2);
}