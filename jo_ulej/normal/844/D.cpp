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

pii ask(int idx)
{
	cout << "? " << idx << endl;
	int val, nxt; cin >> val >> nxt;

	return make_pair(val, nxt);
}

void solve()
{
	int n, start, x, ans = INT_INF; cin >> n >> start >> x;
	int startval = ask(start).first;

	for(int tries = 1000; tries > 0; --tries)
	{
		int idx = randint(1, n);

		auto response = ask(idx);

		if(response.first >= x)
		{
			ans = min(ans, response.first);
		}
		else
		{
			if(response.first >= startval)
				start = response.second, startval = response.first;
		}
	}

	for(int idx = start; idx != -1;)
	{
		auto response = ask(idx);

		if(response.first >= x)
		{
			ans = min(ans, response.first);
			break;
		}

		idx = response.second;
	}

	cout << "! " << (ans == INT_INF ? -1 : ans) << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}