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

vector<int> read()
{
	string str;
	cin >> str;

	vector<int> ret(len(str));

	for(int i = 0; i < len(str); ++i)
		ret[i] = str[i] - '0';

	return ret;
}

void solve()
{
	auto a = read();
   	auto b = read();

	int fxor = 0;

	for(auto elem: b)
		fxor ^= elem;

	vector<int> pref(len(a) + 1, 0);

	for(int i = 1; i <= len(a); ++i)
		pref[i] = pref[i - 1] ^ a[i - 1];

	int answ = 0;

	for(int i = 0; i + len(b) - 1 < len(a); ++i)
	{
		int l = i, r = i + len(b);

		answ += ((pref[r] ^ pref[l]) == fxor);
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}