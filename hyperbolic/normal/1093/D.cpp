#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

std::vector<int> V[300010];
int check[300010],check2[300010];
int getSize(int k)
{
	if(check[k]) return 0;
	check[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++) ans += getSize(V[k][i]);
	return ans;
}

int control;
int func(int k, int h)
{
	if(control) return 0;
	if(check2[k]>0)
	{
		if(check2[k]+h==3) control = 1;
		return 0;
	}
	check2[k] = h;
	int ans = 0;
	if(h==1) ans++;
	for(int i=0;i<V[k].size();i++) ans += func(V[k][i],3-h);
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		control = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) check[i] = check2[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[d].push_back(c);
			V[c].push_back(d);
		}
		
		long long int ans = 1;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				int s = getSize(i);
				int t = func(i,1);
				if(control)
				{
					printf("0\n");
					goto u;
				}
				ans *= (power(2,t)+power(2,s-t));
				ans %= MOD;
			}
		}
		printf("%lld\n",ans);
		u:;
	}
}