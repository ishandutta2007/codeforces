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
	int n;

	cin >> n;
	vector<pll> data(n);

	ll ans = 0;

	for(auto& el: data)
	{
		cin >> el.first >> el.second;

		//if(el.first == el.second)
			//++ans;
	}

	data.insert(data.begin(), make_pair(0, 0));

	for(int i = 0; i < n; ++i)
	{
		ll L1 = data[i].first, R1 = data[i + 1].first;
		ll L2 = data[i].second, R2 = data[i + 1].second;

		ll dlt = max(0LL, min(R1, R2) - max(L1, L2) + 1 - (R1 == R2));
		DBG(dlt);
		ans += dlt;
	}

	if(data.back().first == data.back().second)
		++ans;

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}