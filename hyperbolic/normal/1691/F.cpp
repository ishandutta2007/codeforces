#include <stdio.h>
#include <vector>
#define MOD 1000000007

int prev[200010],size[200010];
std::vector<int> V[200010];
int init(int k, int p)
{
	prev[k] = p;
	size[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		size[k] += init(V[k][i],k);
	}
	return size[k];
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[200010];
long long int comb(int a, int b)
{
	if(a<b) return 0;
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	init(1,0);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int value = 0;
		
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j]==prev[i]) continue;
			value += comb(size[V[i][j]],b), value %= MOD;
		}
		value += comb(a-size[i],b), value %= MOD;
		
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j]==prev[i]) continue;
			int S = a - size[V[i][j]];
			long long int value2 = value + (MOD-comb(size[V[i][j]],b));
			value2 %= MOD;
			long long int value3 = comb(S,b) + (MOD-value2);
			value3 %= MOD;
			
			long long int t = size[V[i][j]]*value3;
			t %= MOD;
			t *= S, t %= MOD;
			ans += t;
			ans %= MOD;
		}
		
		int S = size[i];
		long long int value2 = value + (MOD-comb(a-size[i],b));
		value2 %= MOD;
		long long int value3 = comb(S,b) + (MOD-value2);
		value3 %= MOD;
		
		long long int t = (a-size[i])*value3;
		t %= MOD;
		t *= S, t %= MOD;
		ans += t;
		ans %= MOD;
		
		S = a;
		value3 = comb(S,b) + (MOD-value);
		value3 %= MOD;
		ans += S*value3;
		ans %= MOD;
	}
	printf("%lld",ans);
}