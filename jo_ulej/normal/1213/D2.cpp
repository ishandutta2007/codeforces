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
const int MAX_TRIE_SIZE = MAX_N * 20;

struct Node
{
	int go[2];
	int term = 0;
	int depth = NIL;

	Node()
	{
		memset(go, NIL, sizeof(go));
	}
};

Node trie[MAX_TRIE_SIZE];
int V = 0;

inline int create_vertex()
{
	return V++;
}

inline int addch(int v, int ch)
{
	if(trie[v].go[ch] == NIL)
		trie[v].go[ch] = create_vertex();

	return trie[v].go[ch];
}

int n, k, answ = INT_INF;
int a[MAX_N];

void prepare(int v)
{
	for(int ch = 0; ch < 2; ++ch)
	{
		int u = trie[v].go[ch];

		if(u != NIL)
		{
			trie[u].depth = trie[v].depth + 1;
			prepare(u);
		}
	}
}

struct State
{
	multiset<int>* setik = nullptr;
	int sum = 0;

	void append(int elem)
	{
		if(setik == nullptr)
			setik = new multiset<int>();

		if((int)setik->size() < k)
		{
			setik->insert(elem);
			sum += elem;
		}
		else
		{
			auto mx = prev(setik->end());

			if(elem < *mx)
			{
				sum -= *mx;
				setik->erase(mx);

				sum += elem;
				setik->insert(elem);
			}
		}
	}

	int getsz()
	{
		return (setik == nullptr ? 0 : setik->size());		
	}
};

State merge_state(State lhs, State rhs)
{
	if(lhs.getsz() > rhs.getsz())
		swap(lhs, rhs);	

	if(lhs.setik != nullptr)
	{
		for(auto& elem: *(lhs.setik))
			rhs.append(elem);
	}

	return rhs;
}

State dfs(int v)
{
	State ret;
	
	for(int i = 0; i < trie[v].term; ++i)
		ret.append(trie[v].depth);

	for(int ch = 0; ch < 2; ++ch)
	{
		int u = trie[v].go[ch];

		if(u != NIL)
			ret = merge_state(ret, dfs(u));
	}

	if(ret.getsz() == k)
		answ = min(answ, ret.sum - trie[v].depth * k);

	return ret;
}

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	const int root = create_vertex();

	for(int i = 0; i < n; ++i)
	{
		vector<int> num;
		int j = a[i], v = root;

		for(; j > 0; j >>= 1)
			num.push_back(j & 1);

		reverse(num.begin(), num.end());

		for(auto& ch: num)
			v = addch(v, ch);

		++trie[v].term;
	}

	trie[root].depth = 0;
	prepare(root);

	dfs(root);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}