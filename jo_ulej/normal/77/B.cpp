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
	ld a, b, p;
	cin >> a >> b;

	if(a == 0)
	{
		p = b == 0 ? 1 : 0.5;
	}
	else if(b == 0)
	{
		p = 1;
	}
	else if(a <= 4 * b)
	{
		p = 0.5 + a / (16 * b);
	}
	else
	{
		p = 1 - b / a;
	}

	cout << fixed << setprecision(12) << p << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;

	int q;
	cin >> q;

	for(; q > 0; q--)
		solve();

	return 0;
}