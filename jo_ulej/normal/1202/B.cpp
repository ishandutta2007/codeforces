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

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MOD = 10;

int dist[MOD][MOD];

inline void build(int x, int y)
{
	for(int i = 0; i < MOD; ++i)
	{
		for(int j = 0; j < MOD; ++j)
			dist[i][j] = INT_INF;
	}

	for(int cnt_x = 0; cnt_x < MOD; ++cnt_x)
	{
		for(int cnt_y = 0; cnt_y < MOD; ++cnt_y)
		{
			if(cnt_x + cnt_y == 0)
				continue;

			for(int start = 0; start < MOD; ++start)
			{
				int fin = (start + cnt_x * x + cnt_y * y) % MOD;
				dist[start][fin] = min(dist[start][fin], cnt_x + cnt_y);
			}
		}
	}
}

void solve()
{
	string s;

	cin >> s;
	int n = len(s);

	for(int x = 0; x < 10; ++x)
	{
		for(int y = 0; y < 10; ++y)
		{
			build(x, y);
			int answ = 0;

			for(int i = 0; i + 1 < n; ++i)
			{
				int delta = dist[s[i] - '0'][s[i + 1] - '0'];

				if(delta >= INT_INF)
				{
					answ = NIL;
					break;
				}

				answ += delta - 1;
			}

			cout << answ << " ";
		}

		cout << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}