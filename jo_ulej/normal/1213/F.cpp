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

const int MAX_N = (int)2e5 + 777;

vector<int> g[MAX_N], gT[MAX_N];
int met[MAX_N], mark = 1337;

inline void add_edge(int v, int u)
{
	g[v].push_back(u);
	gT[u].push_back(v);

#ifdef __LOCAL
	cout << "edge: " << v + 1 << " " << u + 1 << endl;
#endif
}

int n, k;
int ord[MAX_N], ord_sz = 0;
int scc[MAX_N], nscc = 0;

void build_ord(int v)
{
	met[v] = mark;

	for(auto& u: g[v])
	{
		if(met[u] != mark)
			build_ord(u);		
	}

	ord[ord_sz++] = v;
}

void compress(int v)
{
	met[v] = mark;
	scc[v] = nscc;

	for(auto& u: gT[v])
	{
		if(met[u] != mark)
			compress(u);
	}	
}

int p[MAX_N];

void solve()
{
	cin >> n >> k;

	for(int t = 0; t < 2; ++t)
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> p[i];
			--p[i];
		}		

		for(int i = 0; i + 1 < n; ++i)
			add_edge(p[i], p[i + 1]);
	}

	for(int v = 0; v < n; ++v)
	{
		if(met[v] != mark)
			build_ord(v);		
	}

	++mark;

	for(int j = ord_sz - 1; j >= 0; --j)
	{
		int v = ord[j];

		if(met[v] != mark)
		{
			compress(v);
			++nscc;
		}
	}

	if(nscc < k)
	{
		cout << "NO" << endl;
	}
	else
	{
		string answ;

		for(int i = 0; i < n; ++i)
		{
			char ch = 'a' + min(scc[i], k - 1);
			answ.push_back(ch);
		}

		cout << "YES" << endl;
		cout << answ << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}