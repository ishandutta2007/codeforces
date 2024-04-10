#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
int a,b,c,d;
long long int check[2010][30];
long long int fact[200010];
long long int power(long long int s, long long int t)
{
	long long int k = s;
	long long int ans = 1;
	while(t)
	{
		if(t%2==1) ans *=k, ans%=MOD;
		k*=k, k%=MOD;
		t/=2;
	}
	return ans;
}

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int comb(int s, int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

struct str{
	int x0;
	int y0;
}x[2010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=c;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	std::sort(x+1,x+c+1,cmp);
	x[0] = {1,1};
	x[c+1] = {a,b};
	
	check[0][0] = 1;
	for(int i=0;i<=c;i++)
	{
		for(int k=i+1;k<=c+1;k++)
		{
			if(x[k].y0>=x[i].y0)
			{
				long long int C = comb(x[k].x0-x[i].x0+x[k].y0-x[i].y0,x[k].x0-x[i].x0);
				C %= MOD;
				
				for(int j=0;j<=21;j++)
				{
					check[k][j+1] += C * check[i][j];
					check[k][j+1] %= MOD;
					if(i>0)
					{
						check[k][j] += C * (MOD-check[i][j]);
						check[k][j] %= MOD;
					}
				}
			}
		}
	}
	
	long long int ans = 0;
	for(int j=1;j<=22;j++)
	{
		ans += d * check[c+1][j];
		ans %= MOD;
		d = (d+1)/2;
	}
	ans *= inv(comb(a+b-2,a-1));
	ans %= MOD;
	printf("%lld",ans);
}