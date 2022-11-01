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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 7777;
const int MAX_LOG_N = 19;

struct Node
{
	int segment_max;
	int segment_or;

	Node(): segment_max(0), segment_or(0)
	{
	}

	Node(int _val): segment_max(_val), segment_or(_val)
	{
	}

	Node operator%(const Node& other) const
	{
		Node answ;
		answ.segment_max = max(segment_max, other.segment_max);
		answ.segment_or = segment_or | other.segment_or;

		return answ;
	}
};

int lg[MAX_N];
int a[MAX_N], n;

Node p[MAX_LOG_N][MAX_N];

void precalc()
{
	lg[1] = 0;

	for(int i = 2; i < MAX_N; ++i)
		lg[i] = 1 + lg[i >> 1];
}

inline Node get(int l, int r)
{
	int log = lg[r - l + 1];

	return p[log][l] % p[log][r - (1 << log) + 1];
}

inline int find_last(int start, int finish)
{
	int low = finish, high = n - 1;

	if(get(start, high).segment_or == get(start, finish).segment_or)
		return high;

	while(high - low > 1)
	{
		int mid = (low + high) / 2;

		if(get(start, mid).segment_or == get(start, finish).segment_or)
			low = mid;
		else
			high = mid;
	}
		
	return low;
}

inline int count(int start, int r1, int r2)
{
	int low = r1, high = r2;

	if(get(start, low).segment_max == get(start, low).segment_or)
		return 0;

	if(get(start, high).segment_max != get(start, high).segment_or)
		return high - r1 + 1;

	while(high - low > 1)
	{
		int mid = (low + high) / 2;

		if(get(start, mid).segment_max != get(start, mid).segment_or)
			low = mid;
		else
			high = mid;
	}

	return low - r1 + 1;
}

void solve()
{
	cin >> n;	

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		p[0][i] = Node(a[i]);
	}

	for(int log = 1; log < MAX_LOG_N; ++log)
	{
		for(int i = 0; i + (1 << log) <= n; ++i)
			p[log][i] = p[log - 1][i] % p[log - 1][i + (1 << (log - 1))];
	}

	ll answ = 0;

	for(int l = 0; l < n; ++l)
	{
		for(int r = l; r < n;)
		{
			int r2 = find_last(l, r);
			answ += count(l, r, r2);

			r = r2 + 1;
		}
	}

	cout << answ << endl;
}

int main()
{
	precalc();

	fast_io();
	solve();

	return 0;
}