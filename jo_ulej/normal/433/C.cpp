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

const int MAX_N = (int)1e5 + 6;

vector<ll> a;
vector<pll> fast[MAX_N];
int n, m;

ll compute(int x, int y)
{
	ll ret = 0;

	for(auto pr: fast[x])
	{
		if(pr.first == x)
			ret += abs(y - pr.second);
		else
			ret += abs(pr.first - y);
	}

	return ret;
}

void solve()
{
	cin >> n >> m;
	a.resize(m);

	for(auto& el: a)
		cin >> el;

	ll initial = 0;

	for(int i = 0; i + 1 < m; ++i)
	{
		if(a[i] == a[i + 1])
			continue;

		fast[a[i]].emplace_back(a[i], a[i + 1]);
		fast[a[i + 1]].emplace_back(a[i], a[i + 1]);
	}

	for(int i = 0; i + 1 < m; ++i)
	{
		initial += abs(a[i + 1] - a[i]);
	}

	/*for(int i = 1; i <= n; ++i)
		initial += compute(i, i);*/

	ll ans = initial;
	DBG(initial);

	for(int i = 1; i <= n; ++i)
	{
		ll L = 1, R = n;

		while(R - L > 100)
		{
			ll M = (L + R) / 2;

			if(compute(i, M + 1) > compute(i, M))
				R = M;
			else
				L = M;
		}

		ll old = compute(i, i);

		for(ll y = L; y <= R; ++y)
			ans = min(ans, initial - old + compute(i, y));

		for(ll y: {1, n})
			ans = min(ans, initial - old + compute(i, y));
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}