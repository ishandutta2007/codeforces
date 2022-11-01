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

ll GCD(ll x, ll y)
{
	return (x == 0 ? y : GCD(y % x, x));
}

const int MOD = (int)1e9 + 7;

int add(int x, int y)
{
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y)
{
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y)
{
	return (x * 1LL * y) % MOD;
}

const int MAX_N = (int)1e5 + 777;
vector<int> g[MAX_N];
ll x[MAX_N];
int n, answ = 0;
int met[MAX_N];

void dfs(int v, map<ll, int>& state)
{
	met[v] = 1;
	vector<ll> vals;

	map<ll, int> n_state;

	for(auto& pr: state)
	{
		ll val = pr.first;
		int cnt = pr.second;

		ll val2 = GCD(val, x[v]);
		n_state[val2] = add(n_state[val2], state[val]);
	}

	n_state[x[v]] = add(n_state[x[v]], 1);

	for(auto& pr: n_state)
	{
		ll val = pr.first % MOD;
		int cnt = pr.second;

		answ = add(answ, mult(val, cnt));
	}

	for(auto& u: g[v])
	{
		if(met[u])
			continue;

		dfs(u, n_state);
	}
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> x[i];

	for(int i = 0; i < n - 1; ++i)
	{
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	map<ll, int> mp;
	dfs(0, mp);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}