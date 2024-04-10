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

const int N_BITS = 20;
const int MAX_N = (int)1e5 + 777;

inline int getbit(int x, int j)
{
	return (x >> j) & 1;
}

inline int setbit(int x, int j)
{
	return x | (1 << j);
}

struct Node
{
	int go[2];
	int sz = 0;

	Node()
	{
		memset(go, NIL, sizeof(go));
	}
};

vector<Node> trie;

inline int create_vertex()
{
	int v = len(trie);
	trie.emplace_back();

	return v;
}

int roots[MAX_N];
vector<int> divisors[MAX_N];

void initialize_and_precalc()
{
	for(int i = 1; i < MAX_N; ++i)
	{
		roots[i] = create_vertex();

		for(int j = i; j < MAX_N; j += i)
			divisors[j].push_back(i);
	}
}

void insert(int v, int number)
{
	for(int j = N_BITS - 1; j >= 0; --j)
	{
		++trie[v].sz;

		if(trie[v].go[getbit(number, j)] == NIL)
			trie[v].go[getbit(number, j)] = create_vertex();

		v = trie[v].go[getbit(number, j)];
	}

	++trie[v].sz;
}

int find(int v, int x, int max, int cur, int j)
{
	if(trie[v].sz == 0 || cur > max)
		return NIL;

	if(j < 0)
		return cur;

	vector<int> ord = {1, 0};

	if(getbit(x, j))
		swap(ord.front(), ord.back());

	for(auto& bit: ord)
	{
		int u = trie[v].go[bit];

		if(u != NIL)
		{
			int n_cur = (bit ? setbit(cur, j) : cur);
			int ret = find(u, x, max, n_cur, j - 1);

			if(ret != NIL)
				return ret;
		}
	}

	return NIL;
}

int find(int v, int x, int max)
{
	return find(v, x, max, 0, N_BITS - 1);		
}

void solve()
{
	int q;
	cin >> q;

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int number;
			cin >> number;

			for(auto& divisor: divisors[number])
				insert(roots[divisor], number);
		}
		else
		{
			int x, k, s;
			cin >> x >> k >> s;

			if(x % k != 0)
			{
				cout << NIL << endl;
				continue;
			}

			int max = s - x;

			if(max < 0)
			{
				cout << NIL << endl;
				continue;
			}

			cout << find(roots[k], x, max) << endl;
		}
	}
}

int main()
{
	fast_io();

	initialize_and_precalc();
	solve();

	return 0;
}