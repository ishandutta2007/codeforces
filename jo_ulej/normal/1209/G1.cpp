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

const int MAX_N = (int)2e5 + 777;
const int MAX_VALUE = (int)2e5 + 777;

int n, q;
int a[MAX_N];
int fst[MAX_N], lst[MAX_N], cnt[MAX_N];

struct Subset
{
	int left, right, count, id;
};

struct SortByLeft
{
	bool operator()(const Subset& lhs, const Subset& rhs) const
	{
		return lhs.left < rhs.left;
	}
};

struct SortByRight
{
	bool operator()(const Subset& lhs, const Subset& rhs) const
	{
		return lhs.right < rhs.right;
	}
};

Subset s[MAX_N];
int head = 0;

vector<int> g[MAX_VALUE];
int met[MAX_VALUE];

void add_edge(int v, int u)
{
#ifdef __LOCAL
	cout << "need to merge " << v << " " << u << endl;
#endif

	g[v].push_back(u);
	g[u].push_back(v);
}

int dfs(int v)
{
	met[v] = 1;
	int mx = cnt[v];

	for(auto& u: g[v])
	{
		if(met[u])
			continue;

		mx = max(mx, dfs(u));		
	}

	return mx;
}

void init()
{
	for(int i = 0; i < MAX_VALUE; ++i)
	{
		fst[i] = INT_INF;
		lst[i] = -INT_INF;
	}
}

void solve()
{
	cin >> n >> q;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];

		fst[a[i]] = min(fst[a[i]], i);
		lst[a[i]] = max(lst[a[i]], i);
		++cnt[a[i]];
	}

	for(int i = 0; i < MAX_VALUE; ++i)
	{
		if(cnt[i] > 0)
		{
			s[head].left  = fst[i];
			s[head].right = lst[i];
			s[head].count = cnt[i];
			s[head].id    = i;

			++head;
		}
	}

	sort(s, s + head, SortByLeft());
	set<Subset, SortByRight> setik;

	for(int i = 0; i < head; ++i)
	{
		if(!setik.empty())
		{
			auto last = prev(setik.end());

			if(last->right >= s[i].left)
				add_edge(last->id, s[i].id);
		}

		setik.insert(s[i]);		
	}

	int answ = n;

	for(int i = 0; i < head; ++i)
	{
		int v = s[i].id;

		if(met[v])
			continue;

		answ -= dfs(v);
	}

	cout << answ << endl;
}

int main()
{
	init();
	fast_io();

	solve();

	return 0;
}