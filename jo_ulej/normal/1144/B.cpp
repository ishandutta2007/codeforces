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

void solve()
{
	vector<ll> even, odd;
	int n;
	ll fsum = 0;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		ll val;
		cin >> val;

		if(val & 1)
			odd.push_back(val);
		else
			even.push_back(val);

		fsum += val;
	}	

	sort(even.rbegin(), even.rend());
	sort(odd.rbegin(), odd.rend());

	ll ans = LL_INF;

	if(!even.empty())
		ans = min(ans, fsum - even.front());

	if(!odd.empty())
		ans = min(ans, fsum - odd.front());

	ll psum = 0;

	for(int j = 0; j < even.size() && j < odd.size(); ++j)
	{
		psum += even[j] + odd[j];

		ans = min(ans, fsum - psum);

		if(j + 1 < even.size())
			ans = min(ans, fsum - psum - even[j + 1]);

		if(j + 1 < odd.size())
			ans = min(ans, fsum - psum - odd[j + 1]);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}