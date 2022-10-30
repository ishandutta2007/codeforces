#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e7 + 9;

void solve_case()
{
	ll k;
	bool a[7];

	cin >> k;

	for(int i = 0; i < 7; ++i)
		cin >> a[i];

	ll sm = 0;

	for(int i = 0; i < 7; ++i)
		sm += a[i];

	ll len = 7 * ((k - 1) / sm + 1);
	ll ans = len;

	ll L = 0;
	ll R = len - 1;

	while(!a[L % 7] && L < R)
		++L;

	while(!a[R % 7] && L < R)
		--R;

	ans = min(ans, R - L + 1);

	ll st = sm * (len / 7);

	for(int step = 0; step < 100; ++step)
	{
		if(a[(L++) % 7])
			--st;

		while(st < k)
			st += a[(++R) % 7];

		ans = min(ans, R - L + 1);
	}

	cout << ans << "\n";
}

void solve()
{
	int t;
	cin >> t;

	for(; t > 0; --t)
		solve_case();
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}