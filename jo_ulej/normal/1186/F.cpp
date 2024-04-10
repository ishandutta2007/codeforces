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

const int MAX_N = (int)1e6 + 77;

int d[MAX_N], cur_d[MAX_N];

vector<pii> edges, answ;
vector<bool> used;

int n, m;

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		++d[v], ++d[u];

		edges.emplace_back(v, u);
		used.push_back(false);
	}

	shuffle(edges.begin(), edges.end(), _g);

	for(int i = 0; i < m; ++i)
	{
		int v = edges[i].first, u = edges[i].second;

		if(cur_d[v] < (d[v] >> 1) + (d[v] & 1) && cur_d[u] < (d[u] >> 1) + (d[u] & 1))
		{
			++cur_d[v];
			++cur_d[u];

			used[i] = true;
		}
	}
	
	for(int i = 0; i < m; ++i)
	{
		int v = edges[i].first, u = edges[i].second;

		if(used[i])
			continue;

		if(cur_d[v] < (d[v] >> 1) + (d[v] & 1) || cur_d[u] < (d[u] >> 1) + (d[u] & 1))
		{
			++cur_d[v];
			++cur_d[u];

			used[i] = true;
		}
	}

	for(int i = 0; i < m; ++i)
		if(used[i])
			answ.push_back(edges[i]);

#define endl '\n'

	cout << len(answ) << endl;

	for(auto& ed: answ)
		cout << ed.first + 1 << " " << ed.second + 1 << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}