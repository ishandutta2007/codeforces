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

#pragma GCC optimize("Ofast")

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

inline int convert(char chr)
{
	static string alphabet = "ACGT";

	return lower_bound(alphabet.begin(), alphabet.end(), chr) - alphabet.begin();
}

const int N_COLS = 4;
const int MAX_N = (int)2e5 + 777;

bitset<MAX_N> mask[N_COLS];
bitset<MAX_N> answ;

int pref[N_COLS][MAX_N];

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	string s, t;
	cin >> s >> t;

	for(int i = 0; i < n; ++i)
		pref[convert(s[i])][i] = 1;

	for(int ch = 0; ch < N_COLS; ++ch)
	{
		for(int i = 1; i < n; ++i)
			pref[ch][i] += pref[ch][i - 1];
	}

	for(int ch = 0; ch < N_COLS; ++ch)
	{
		for(int i = 0; i < n; ++i)
		{
			int l = (i - k < 0 ? 0 : i - k);
			int r = (i + k > n - 1 ? n - 1 : i + k);

			int sum = pref[ch][r];

			if(l > 0)
				sum -= pref[ch][l - 1];

			mask[ch][i] = (sum > 0);
		}
	}

	for(int i = 0; i < n - m + 1; ++i)
		answ[i] = 1;

	for(int j = 0; j < m; ++j)
	{
		int ch = convert(t[j]);
		answ &= (mask[ch] >> j);
	}

	cout << answ.count() << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}