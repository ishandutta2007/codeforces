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

void solve()
{
	int n;
	cin >> n;
	n = 4 * n + 1;

	vector<pii> pts(n);

	for(auto& point: pts)
		cin >> point.first >> point.second;

	for(int x1 = -1; x1 <= 57; ++x1)
	{
		for(int y1 = -1; y1 <= 57; ++y1)
		{
			for(int x2 = x1; x2 <= 57; ++x2)
			{
				for(int y2 = y1; y2 <= 57; ++y2)
				{
					int cnt_bad = 0;
					pii bad_point;

					for(auto point: pts)
					{
						int x = point.first, y = point.second;

						if((x1 <= x && x <= x2) && (y == y1 || y == y2))
							continue;

						if((y1 <= y && y <= y2) && (x == x1 || x == x2))
							continue;

						++cnt_bad;
						bad_point = point;
					}

					if(cnt_bad == 1)
					{
						cout << bad_point.first << " " << bad_point.second << endl;
						return;
					}
				}
			}
		}
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}