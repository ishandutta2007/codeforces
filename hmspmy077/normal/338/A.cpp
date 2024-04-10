#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())

const int mo = 1000000009;

long long cal(long long i, long long j)
{
	if (j == 0) return 1;
	if (j % 2 == 1) return i * cal(i, j - 1) % mo;
	long long t = cal(i, j / 2);
	return t * t % mo;
}

long long fix(long long a)
{
	a %= mo;
	if (a < 0) a += mo;
	return a;
}

int main()
{
	#ifdef LOCAL_TEST
	//	freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	long long s = max(m - n + n / k, 0);
	long long ans = fix(cal(2, s + 1) - 2);
	ans = ans * k % mo;
	ans += (m - s * k % mo);
	ans = fix(ans);
	cout << ans << endl;
	return 0;
}