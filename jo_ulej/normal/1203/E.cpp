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

const int MAX_VALUE = 150000 + 777;

int cnt[MAX_VALUE], cnt2[MAX_VALUE], n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		++cnt[x];
	}

	int answ = 0;

	for(int x = 1; x < MAX_VALUE; ++x)
	{
		for(int t: {-1, 0, 1})
		{
			if(cnt[x] > 0 && x + t > 0 && cnt2[x + t] == 0)
			{
				++cnt2[x + t];
				--cnt[x];

				answ += (cnt2[x + t] == 1);
			}
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