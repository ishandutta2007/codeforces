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
	int n;
	string s;

	cin >> n >> s;

	if(n > 2 || s[0] < s[1])
	{
		cout << "YES" << endl;
		cout << 2 << endl;

		cout << s[0] << " " << s.substr(1, s.size() - 1) << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main(int argc, char** argv)
{
	FAST_IO;

	int q;
	cin >> q;

	for(; q > 0; --q)
		solve();

	return 0;
}