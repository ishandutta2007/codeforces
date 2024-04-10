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

const int MAX_N = (int)2e5 + 777;
const int N_DIGITS = 10;

void append(pii& pr, int x)
{
	if(x <= pr.first)
	{
		pr.second = pr.first;
		pr.first = x;
	}
	else if(x < pr.second)
	{
		pr.second = x;
	}
}

struct Node
{
	pii mins[N_DIGITS];

	Node()
	{
		for(int j = 0; j < N_DIGITS; ++j)
			mins[j] = make_pair(INT_INF, INT_INF);
	}

	void init(int num)
	{
		int temp = num;

		for(int j = N_DIGITS - 1; j >= 0; --j)
		{
			mins[j] = make_pair(INT_INF, INT_INF);

			if(temp % 10 != 0)
				append(mins[j], num);

			temp /= 10;
		}
	}

	Node combine(const Node& other) const
	{
		Node answ;

		for(int j = 0; j < N_DIGITS; ++j)
		{
			answ.mins[j] = make_pair(INT_INF, INT_INF);

			append(answ.mins[j], mins[j].first);
			append(answ.mins[j], mins[j].second);

			append(answ.mins[j], other.mins[j].first);
			append(answ.mins[j], other.mins[j].second);
		}

		return answ;
	}
};

Node tree[2 * MAX_N];
int a[MAX_N], n, q;

void build()
{
	for(int i = 0; i < n; ++i)
		tree[i + n].init(a[i]);

	for(int i = n - 1; i > 0; --i)
		tree[i] = tree[2 * i].combine(tree[2 * i + 1]);
}

void change(int pos, int val)
{
	pos += n;
	tree[pos].init(val);

	for(; pos > 1; pos /= 2)
		tree[pos / 2] = tree[pos].combine(tree[pos ^ 1]);
}

Node get(int l, int r)
{
	l += n;
	r += n + 1;

	Node acc;

	while(l < r)
	{
		if(l & 1)
			acc = acc.combine(tree[l++]);

		if(r & 1)
			acc = acc.combine(tree[--r]);

		l /= 2;
		r /= 2;
	}

	return acc;
}

void solve()
{
	cin >> n >> q;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	build();

	while(q--)
	{
		int t;
		cin >> t;

		if(t == 1)
		{
			int i, x;
			cin >> i >> x;
			--i;

			change(i, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			--l, --r;

			Node answ = get(l, r);
			int best = INT_INF + 228;

			for(int j = 0; j < N_DIGITS; ++j)
			{
				if(answ.mins[j].second < INT_INF)
				{
					int sum = answ.mins[j].first + answ.mins[j].second;
					best = (best < sum ? best : sum);
				}
			}

			cout << (best >= INT_INF ? NIL : best) << endl;
		}
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}