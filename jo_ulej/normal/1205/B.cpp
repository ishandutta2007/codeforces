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

const int MAX_N = (int)1e5 + 77;
const int N_BITS = 63;

ll a[MAX_N], n;
vector<int> groups[N_BITS];

struct Edge
{
	int from, to;
	bool active;

	Edge(): from(NIL), to(NIL), active(false)
	{
	}

	Edge(int _from, int _to): from(_from), to(_to), active(true)
	{
	}
};

Edge edges[2 * MAX_N];
vector<int> g[MAX_N];

int E = 0;

inline void add_edge(int v, int u)
{
#ifdef __LOCAL
	cout << "adding edge: " << v << " " << u << endl;
#endif

	edges[2 * E] = Edge(v, u);
	edges[2 * E + 1] = Edge(u, v);
	
	g[v].push_back(2 * E);
	g[u].push_back(2 * E + 1);

	++E;
}

int q[MAX_N], qsz = 0;
int d[MAX_N];

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];

		for(ll j = 0; j < N_BITS; ++j)
		{
			if((a[i] >> j) & 1LL)
			{
				groups[j].push_back(i);

				if(len(groups[j]) == 3)
				{
					cout << "3" << endl;
					return;
				}
			}
		}
	}

	vector<pii> prs;

	for(int j = 0; j < N_BITS; ++j)
	{
		for(auto& v: groups[j])
		{
			for(auto& u: groups[j])
			{
				if(v < u)
					prs.emplace_back(v, u);
			}
		}
	}

	sort(prs.begin(), prs.end());
	prs.erase(unique(prs.begin(), prs.end()), prs.end());

	for(auto& pr: prs)
		add_edge(pr.first, pr.second);

	int answ = INT_INF;

	for(int ed = 0; ed < E; ++ed)
	{
		edges[2 * ed].active = edges[2 * ed + 1].active = false;

		int start = edges[2 * ed].from;
		int finish = edges[2 * ed].to;

		for(int v = 0; v < n; ++v)
			d[v] = INT_INF;

		d[start] = 0;

		qsz = 0;
		q[qsz++] = start;

		for(int j = 0; j < qsz; ++j)
		{
			int v = q[j];

			for(auto& id: g[v])
			{
				if(!edges[id].active)
					continue;

				int u = edges[id].to;

				if(d[u] > d[v] + 1)
				{
					d[u] = d[v] + 1;
					q[qsz++] = u;
				}
			}
		}

		answ = min(answ, d[finish] + 1);
		edges[2 * ed].active = edges[2 * ed + 1].active = true;
	}

	cout << (answ == INT_INF ? -1 : answ) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}