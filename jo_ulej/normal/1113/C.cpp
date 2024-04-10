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

	vector<ll> arr(n), prefxor(n + 1);

	for(auto& el: arr)
		cin >> el;

	prefxor[0] = 0;

	for(int i = 1; i <= n; ++i)
		prefxor[i] = (arr[i - 1] ^ prefxor[i - 1]);

	map<pair<ll, ll>, vector<int>*> mp;
	ll ans = 0;

	for(int r = 0; r <= n; ++r)
	{
		auto p = make_pair(prefxor[r], r % 2);

		if(mp.find(p) != mp.end())
			ans += mp[p]->size();
		
		if(mp.find(p) == mp.end())
			mp.insert(make_pair(p, new vector<int>()));

		mp[p]->push_back(r);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}