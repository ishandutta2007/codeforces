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
	int n;
	cin >> n;

	vector<ll> s(n);

	for(auto& el: s)
		cin >> el;

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	n = s.size();

	vector<ll> d;

	for(int i = 0; i + 1 < n; ++i)
		d.push_back(s[i + 1] - s[i]);

	if(d.empty())
		d.push_back(0);

	sort(d.begin(), d.end());
	int sz = d.size();

	vector<ll> suffsum(sz);
	suffsum[sz - 1] = d[sz - 1];

	for(int i = sz - 2; i >= 0; --i)
		suffsum[i] = suffsum[i + 1] + d[i];

	int q;
	cin >> q;

	string out;

	for(; q > 0; --q)
	{
		ll l, r;
		cin >> l >> r;
		ll len = r - l + 1;

		ll ans = (s[n - 1] + len - 1) - s[0] + 1;

		int j = upper_bound(d.begin(), d.end(), len) - d.begin();

		if(j < sz)
			ans -= suffsum[j] - (sz - j) * len;

		out += to_string(ans) + " ";
	}

	cout << out << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}