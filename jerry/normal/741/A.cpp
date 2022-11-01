#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[105];
int to[105];
int n;

ll gcd(ll a, ll b)
{
	return b?gcd(b, a%b):a;
}

ll lcm(ll a, ll b)
{
	return a/gcd(a, b)*b;
}

ll dfs(int at, int fr)
{
	if (vis[at])
	{
		if (at == fr) return 0;
		return -1;
	}
	vis[at] = true;
	ll ret = dfs(to[at], fr);
	if (ret == -1) return -1;
	return ret+1;
}

int main()
{
	ll ans = 1;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", to+i), --to[i];
	for (int i = 0;i < n;i++) if (!vis[i])
	{
		ll tmp = dfs(i, i);
		if (tmp == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		if (tmp&1) ans = lcm(ans, tmp);
		else ans = lcm(ans, tmp/2);
	}
	cout << ans << endl;
	return 0;
}