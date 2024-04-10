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

const ll mod = 998244353LL;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)1e5 + 77;
const int MAX_LEN = 11;

string s[MAX_N];
ll cnt[MAX_LEN];

int n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());

		++cnt[len(s[i])];
	}

	ll answ = 0;

	for(int i = 0; i < n; ++i)
	{
		// s[i] as first argument
		for(int length = 0; length < MAX_LEN; ++length)
		{
			ll pow = 1LL;
			ll add = 0;

			for(int j = 0; j < len(s[i]); ++j)
			{
				ll d = s[i][j] - '0';
				ll f = j < length ? 10LL : 1LL;

				add = (add + pow * f * d) % mod;
				pow = (10L * f * pow) % mod;
			}

			if(cnt[length])
			{
				DBG(s[i]); DBG(cnt[length] * add);
			}

			answ = (answ + cnt[length] * add) % mod;
		}

		// s[i] as second argument
		for(int length = 0; length < MAX_LEN; ++length)
		{
			ll pow = 1LL;
			ll add = 0;

			for(int j = 0; j < len(s[i]); ++j)
			{
				ll d = s[i][j] - '0';
				ll f = j < length ? 10LL : 1LL;

				add = (add + pow * d) % mod;
				pow = (10L * f * pow) % mod;
			}

			if(cnt[length])
			{
				DBG(s[i]); DBG(cnt[length] * add);
			}

			answ = (answ + cnt[length] * add) % mod;
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}