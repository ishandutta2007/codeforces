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

ll ask(int i, int j)
{
	ll ret;

	cout << "? " << i + 1 << " " << j + 1 << endl;
	cin >> ret;

	return ret;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);

	for(int i = 1; i < n; ++i)
		a[i] = ask(0, i);

	ll x = ask(1, 2);

	a[0] = (a[1] + a[2] - x) / 2;

	for(int i = 1; i < n; ++i)
		a[i] -= a[0];

	cout << "! ";

	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	solve();

	return 0;
}