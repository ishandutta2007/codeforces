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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

void solve()
{
	ll x, y, z, a, b, c; cin >> x >> y >> z >> a >> b >> c;

	a -= x;

	if(a < 0)
	{
		cout << "NO" << endl;
		return;
	}

	int k = a + b;

	k -= y;

	if(k < 0)
	{
		cout << "NO" << endl;
		return;
	}

	if(k + c < z)
	{
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}