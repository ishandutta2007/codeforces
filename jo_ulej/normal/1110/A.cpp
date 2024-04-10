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
	ll b, n = 0;
	int k;

	cin >> b >> k;

	for(int i = 0; i < k; ++i)
	{
		ll digit;
		cin >> digit;

		n = (b * n) % 2;
		n = (n + digit) % 2;
	}

	if(n == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}