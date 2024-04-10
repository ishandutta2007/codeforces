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

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAX_N = 10;
const int MAX_M = 177;

int n, m;

struct Column
{
	int arr[MAX_N];

	int getmax() const
	{
		int mx = -INT_INF;

		for(int i = 0; i < n; ++i)
			mx = max(mx, arr[i]);

		return mx;
	}

	bool operator<(const Column& other) const
	{
		return getmax() > other.getmax();
	}

	void shift()
	{
		arr[n] = arr[0];

		for(int i = 0; i < n; ++i)
			arr[i] = arr[i + 1];
	}
};

Column cols[MAX_M];
int answ;

void go(int i)
{
	if(i == n)
	{
		int local = 0;

		for(int row = 0; row < n; ++row)
		{
			int mx = -INT_INF;

			for(int col = 0; col < m; ++col)
				mx = max(mx, cols[col].arr[row]);

			local += mx;
		}

		answ = max(answ, local);
	}
	else
	{
		for(int j = 0; j < n; ++j)
		{
			go(i + 1);
			cols[j].shift();
		}
	}
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cols[j].arr[i] = fetch<int>();
	}

	sort(cols, cols + m);
	answ = -INT_INF;
	go(0);

	cout << answ << endl;
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}