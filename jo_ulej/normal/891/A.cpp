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

#ifndef __LOCAL
#define gcd __gcd
#endif

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for(auto& elem: a)
		cin >> elem;

	int answ = INT_INF;
	int cnt_ones = 0;

	for(int i = 0; i < n; ++i)
		cnt_ones += (a[i] == 1);

	for(int l = 0; l < n; ++l)
	{
		int cur = a[l];
		int cur_cnt_ones = (a[l] == 1);

		if(cur == 1)
		{
			int local = n - 1 - (cnt_ones - cur_cnt_ones);

			answ = min(answ, local);
		}

		for(int r = l + 1; r < n; ++r)
		{
			cur = gcd(cur, a[r]);
			cur_cnt_ones += (a[r] == 1);

			if(cur == 1)
			{
				int local = n - 1 + r - l - (cnt_ones - cur_cnt_ones);

				answ = min(answ, local);
			}
		}
	}
	
	cout << (answ == INT_INF ? -1 : answ) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}