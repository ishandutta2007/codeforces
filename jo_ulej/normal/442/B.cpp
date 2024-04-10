#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << fixed << setprecision(12) << #X << "=" << (X) << endl;
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

ld stupid(const vector<ld>& p)
{
	int n = p.size();
	ld ret = 0;

	for(int msk = 1; msk < (1 << n); ++msk)
	{
		ld a = 0, b = 1;

		for(int i = 0; i < n; ++i)
		{
			if(msk & (1 << i))
			{
				a += p[i] / (1.0 - p[i]);
				b *= (1.0 - p[i]);
			}
		}

		ret = max(ret, a * b);
	}

	return ret;
}

void solve()
{
	int n;
	cin >> n;

	vector<ld> p(n);

	for(auto& el: p)
		cin >> el;

	sort(p.rbegin(), p.rend());

	ld ans = 0;

	for(int i = 0; i < n; ++i)
	{
		if(p[i] == 1.0)
		{
			cout << fixed << setprecision(12) << (ld)1.0 << endl;
			return;
		}

		for(int j = i; j < n; ++j)
		{
			ld a = 0, b = 1;

			for(int k = i; k <= j; ++k)
			{
				a += p[k] / (1.0 - p[k]);
				b *= (1.0 - p[k]);
			}

			ans = max(ans, a * b);
		}
	}

	DBG(stupid(p));

	cout << fixed << setprecision(12) << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}