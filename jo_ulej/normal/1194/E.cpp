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
 
#pragma GCC optimize("Ofast,unroll-loops,fast-math")

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

bool intr(int l1, int r1, int l2, int r2)
{
	if(l1 > r1)
		swap(l1, r1);

	if(l2 > r2)
		swap(l2, r2);

	return min(r1, r2) >= max(l1, l2);
}

struct Segment
{
	int x1, x2, y1, y2;

	bool intrsect(const Segment& other) const
	{
		return intr(x1, x2, other.x1, other.x2) && intr(y1, y2, other.y1, other.y2);
	}
};

const int MAX_N = 5007;

vector<Segment> vert, hor;
int n, V, H;

bitset<MAX_N> m[MAX_N];

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		Segment s;
		cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;

		if(s.x1 == s.x2)
			vert.push_back(s);
		else
			hor.push_back(s);
	}

	if(len(vert) > len(hor))
		swap(vert, hor);

	V = len(vert), H = len(hor);

	for(int i = 0; i < V; ++i)
		for(int j = 0; j < H; ++j)
			m[i][j] = vert[i].intrsect(hor[j]);

	ll answ = 0;

	for(int i1 = 0; i1 < V; ++i1)
	{
		for(int i2 = 0; i2 < i1; ++i2)
		{
			auto a = m[i1] & m[i2];

			ll cnt = a.count();
			answ += (cnt * (cnt - 1)) / 2;
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