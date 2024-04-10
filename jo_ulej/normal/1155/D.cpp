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
	ll x;

	cin >> n >> x;
	vector<ll> a(n);

	for(auto& el: a)
		cin >> el;

	a.push_back(0);

	if(x > 0)
	{
		ll pref = 0, minpref = 0;
		ll answ = 0;

		for(int i = 0; i < n; ++i)
		{
			pref += a[i];
			answ = max(answ, x * (pref - minpref));

			minpref = min(minpref, pref);
		}	

		cout << answ << endl;
	}
	else
	{
		ll pref = 0, maxpref = 0, maxmagic = 0;
		int l = -1;
		ll answ = 0;

		vector<ll> best(n + 2, 0), best2(n + 1, 0);

		for(int i = n - 1; i >= 0; --i)
			best[i] = a[i] + max(0LL, best[i + 1]);

		best2[0] = a[0];

		for(int i = 1; i < n; ++i)
			best2[i] = a[i] + max(0LL, best2[i - 1]);

		best2[n] = best2[n - 1];

		DBG(best);

		for(int i = 0; i <= n; ++i)
		{
			pref += a[i];

			//answ = max(answ, x * (pref - maxpref) + max(best[i + 1], 0LL) + max((l >= 0 ? best2[l] : 0), 0LL));
			answ = max(answ, x * pref + max(best[i + 1], 0LL) + maxmagic);
			DBG(i);
			DBG((pref - maxpref));
			DBG(best2[l]); DBG(l);
			DBG(answ);
			DBG(best[i]);

			if(i < n)
			{
				if(maxpref < pref)
					l = i;
				else if(maxpref == pref && (best2[i] > best2[l]))
					l = i;

				maxpref = max(maxpref, pref);

				maxmagic = max(maxmagic, -x * pref + max(0LL, best2[i]));
			}
		}

		cout << answ << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}