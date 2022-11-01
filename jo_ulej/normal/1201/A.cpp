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

const int MAX_N = 1007;
const int MAX_M = 1007;

string matr[MAX_N];
int n, m, a[MAX_M];

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> matr[i];

	for(int i = 0; i < m; ++i)
		cin >> a[i];

	int answ = 0;

	for(int que = 0; que < m; ++que)
	{
		int dlt = 0;

		for(char cor = 'A'; cor <= 'E'; ++cor)
		{
			int local = 0;

			for(int i = 0; i < n; ++i)
				local += a[que] * (matr[i][que] == cor);

			dlt = max(dlt, local);
		}

		answ += dlt;
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}