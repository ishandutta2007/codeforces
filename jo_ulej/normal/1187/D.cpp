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

const int MAX_N = (int)3e5 + 777;

int tree[2 * MAX_N], n;

inline void create(const vector<int>& a)
{
	for(int i = 0; i < n; ++i)
		tree[i + n] = a[i];

	for(int i = n - 1; i > 0; --i)
		tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

inline void ch(int i, int x)
{
	i += n;
	tree[i] = x;

	while(i != 1)
	{
		i /= 2;
		tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	}
}

inline int get(int l, int r)
{
	l += n, r += n + 1;
	int acc = 0;

	while(l != r)
	{
		if(l & 1)
			acc = max(acc, tree[l++]);

		if(r & 1)
			acc = max(acc, tree[--r]);

		l /= 2, r /= 2;
	}

	return acc;
}

vector<int> pos[MAX_N];

void solve()
{
	cin >> n;

	for(int i = 0; i < 2 * n + 7; ++i)
		tree[i] = 0;

	for(int i = 0; i < n + 7; ++i)
		pos[i].clear();

	vector<int> a(n), b(n);

	for(auto& elem: a)
		cin >> elem;

	for(auto& elem: b)
		cin >> elem;

	for(int i = 0; i < n; ++i)
		pos[a[i]].push_back(i);

	create(a);

	int j = n - 1;

	while(j >= 0)
	{
		DBG(j); DBG(a); DBG(b);

		int wanted = b[j];

		if(pos[wanted].empty())
		{
			cout << "NO" << endl;
			return;
		}
		
		int index = pos[wanted].back();
		pos[wanted].pop_back();

		if(get(index, n - 1) > wanted)
		{
			cout << "NO" << endl;
			return;
		}

		a[index] = NIL;
		ch(index, NIL);

		--j;
	}

	cout << "YES\n";
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	for(; T; --T)
		solve();

	return 0;
}