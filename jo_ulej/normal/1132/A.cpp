#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

void solve()
{
	int cnt[5];

	cin >> cnt[1] >> cnt[2] >> cnt[3] >> cnt[4];

	int bal = 2 * cnt[1];

	if(bal - (cnt[3] > 0) < 0 || bal - 2 * cnt[4] != 0)
		cout << "0" << endl;
	else
		cout << "1" << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}