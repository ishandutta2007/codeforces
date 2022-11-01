#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAX_N = (int)1e6 + 77;

ll a[MAX_N], answ = 0;
int n;

ll prefs[MAX_N], suffs[MAX_N];
int p_head = 0, s_head = 0;

void calc(int l, int r)
{
	if(r - l == 1)
	{
		answ += a[l];		
	}
	else
	{
		int m = (l + r) / 2;
		
		calc(l, m);
		calc(m, r);

		p_head = s_head = 0;
		
		prefs[p_head++] = a[m - 1];

		for(int i = m - 2; i >= l; --i)
		{
			ll old = prefs[p_head - 1];
			prefs[p_head++] = max(old, a[i]);		
		}

		suffs[s_head++] = a[m];

		for(int i = m + 1; i < r; ++i)
		{
			ll old = suffs[s_head - 1];
			suffs[s_head++] = max(old, a[i]);
		}

		sort(prefs, prefs + p_head);
		sort(suffs, suffs + s_head);

		for(int i = 0; i < p_head; ++i)
		{
			ll mx = prefs[i];
			ll cnt = upper_bound(suffs, suffs + s_head, mx) - suffs;

			answ += cnt * mx;
		}

		for(int i = 0; i < s_head; ++i)
		{
			ll mx = suffs[i];
			ll cnt = upper_bound(prefs, prefs + p_head, mx) - prefs;

			answ += cnt * mx;
		}

		for(int i = 0; i < p_head; ++i)
		{
			ll mx = prefs[i];
			ll cnt = upper_bound(suffs, suffs + s_head, mx) - lower_bound(suffs, suffs + s_head, mx);		

			answ -= cnt * mx;
		}
	}
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	calc(0, n);

	for(int i = 0; i < n; ++i)
		a[i] = -a[i];

	calc(0, n);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}