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

#pragma GCC optimize("Ofast,unroll-loops")

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

const int N = 500000 + 777;
const int M = 507;

ll a[N], b[M][M];
int q;

void solve()
{
	cin >> q;
	string output;

	while(q--)
	{
		int t, x, y;
		cin >> t >> x >> y;

		if(t == 1)
		{
			a[x] += y;

			for(int m = 1; m < M; ++m)
				b[m][x % m] += y;		
		}
		else
		{
			ll answ = 0;

			if(x < M)
			{
				answ += b[x][y];
			}
			else
			{
				for(int pos = y; pos < N; pos += x)
					answ += a[pos];
			}

			output += to_string(answ);
			output.push_back('\n');
		}
	}

	cout << output << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}