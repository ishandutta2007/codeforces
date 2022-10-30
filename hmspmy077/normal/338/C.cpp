#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())

map<long long, int> f;
long long a[10];
int n, ans, d[10];

int cal(long long x)
{
	if (x == 1) return 0;
	if (f.count(x)) return f[x];
	for (int i = 2; 1LL * i * i <= x; ++i)
		if (x % i == 0)
			return f[x] = cal(x / i) + 1;
	return f[x] = 1;
}

void dfs(int i)
{
	if (i == -1)
	{
		int tmp = d[n] > 1;
		for (int j = 0; j < n; ++j)
		{
			tmp += cal(a[j]);
			if (d[j] || cal(a[j]) != 1)
				++tmp;
		}
		ans = min(ans, tmp);
		return;
	}
	for (int j = i + 1; j <= n; ++j)
	{
		if (a[j] % a[i] != 0) continue;
		a[j] /= a[i];
		++d[j];
		dfs(i - 1);
		--d[j];
		a[j] *= a[i];
	}
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	ans = 10000000;
	dfs(n - 1);
	cout << ans << endl;
	return 0;
}