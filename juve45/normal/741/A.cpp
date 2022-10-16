
#include <bits/stdc++.h>
#define DMAX 110
using namespace std;

long long x, ans = 1;

long long n, v[DMAX], use[DMAX], c[DMAX];


long long dfs(long long x, long long t)
{
	if(use[x] == 1)return -1000;
	use[x] = 1;

	if(x==t) 
		return 1;
	return dfs(v[x], t) + 1;
}

long long lcm(long long a, long long b)
{
	return a*b/__gcd(a, b);
}

int main()
{

	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> v[i];
	}

	for(long long i=1;i<=n;i++)
	{
		memset(use, 0, sizeof(long long)*DMAX);
		c[i] = dfs(v[i], i);
	}

	for(long long i=1;i<=n;i++)
	{
		if(c[i] < 0)
		{
			cout << -1;
			return 0;
		}
		if(c[i]%2 == 0) c[i]/=2;
		ans = lcm(ans, c[i]);
	}
	cout << ans << '\n';
	return 0;
}