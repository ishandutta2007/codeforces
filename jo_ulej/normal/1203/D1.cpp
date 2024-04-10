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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int ALPHABET = 30;
const int MAX_LEN  = (int)2e5 + 777;

string s, t;

vector<int> pos[ALPHABET];
int n;

inline int nxt(const vector<int>& v, int a)
{
	auto iter = upper_bound(v.begin(), v.end(), a);

	return (iter != v.end() ? *iter : INT_INF);
}

inline int prv(const vector<int>& v, int a)
{
	auto iter = lower_bound(v.begin(), v.end(), a);

	return (iter != v.begin() ? *(iter - 1) : -INT_INF);
}

int dp1[MAX_LEN], dp2[MAX_LEN];

void solve()
{
	cin >> s >> t;
	n = len(s);

	for(int i = 0; i < n; ++i)
		pos[s[i] - 'a'].push_back(i);

	for(int pref = 1; pref <= len(t); ++pref)
	{
		char ch = t[pref - 1];
		dp1[pref] = nxt(pos[ch - 'a'], dp1[pref - 1] - 1) + 1;
	}

	for(int suff = 1; suff <= len(t); ++suff)
	{
		char ch = t[len(t) - suff];
		dp2[suff] = n - prv(pos[ch - 'a'], n - dp2[suff - 1]);
	}

	int answ = INT_INF;

	for(int pref = 0; pref <= len(t); ++pref)
	{
		int suff = len(t) - pref;
		answ = min(answ, dp1[pref] + dp2[suff]);		
	}

	cout << n - answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}