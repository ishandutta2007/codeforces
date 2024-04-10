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

ll n, k;
ll ans = INT_INF;

void find_sol(ll a)
{
	for(ll x = k * a; x < k * a + k; ++x)
		if(a * (x % k) == n)
			ans = min(ans, x);
}

void solve()
{
	cin >> n >> k;

	for(ll d = 1; d * d <= n; ++d)
		if(n % d == 0)
			find_sol(d), find_sol(n / d);

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

    return 0;
}