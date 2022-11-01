#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

ll calc(const vector<ll>& v)
{
	ll ret = 0;

	for(int i = 0; 2 * i + 1 < v.size(); ++i)
		ret += max(v[2 * i], v[2 * i + 1]);

	return ret;
}

void solve()
{
	int n;
	ll h;
	cin >> n >> h;

	vector<ll> a(n);

	for(auto& el: a)
		cin >> el;

	int ans = 0;

	for(int k = 0; k < n; ++k)
	{
		vector<ll> v;

		for(int i = 0; i <= k; ++i)
			v.push_back(a[i]);

		sort(v.rbegin(), v.rend());

		ll sm1 = 0, sm2 = 0;

		if((k + 1) & 1)
		{
			auto v1 = v, v2 = v;

			v1.push_back(0);
			v2.insert(v2.begin(), 0);

			sm1 = calc(v1);
			sm2 = calc(v2);
		}
		else
		{
			sm1 = sm2 = calc(v);
		}

		if(min(sm1, sm2) <= h)
			ans = max(ans, k + 1);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}