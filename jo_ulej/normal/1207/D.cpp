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

const int MOD = 998244353;

inline int add(int x, int y)
{
	int r = x + y;

	return (r >= MOD ? r - MOD : r);
}

inline int sub(int x, int y)
{
	int r = x - y;
	
	return (r < 0 ? r + MOD : r);	
}

inline int mult(int x, int y)
{
	return (x * 1LL * y) % MOD;
}
	
const int MAX_N = (int)3e5 + 777;

int n, fact[MAX_N];
pii a[MAX_N];

void solve()
{
	fact[0] = 1;

	for(int i = 1; i < MAX_N; ++i)
		fact[i] = mult(fact[i - 1], i);

	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;

	int answ = fact[n];
	int subtract1 = 1, subtract2 = 1, subtract3 = 1;

	sort(a, a + n);

	for(int i = 0; i < n;)
	{
		int j = i;

		while(j + 1 < n && a[j + 1].first == a[i].first)
			++j;

		subtract1 = mult(subtract1, fact[j - i + 1]);
		i = j + 1;
	}

	bool fl = true;

	for(int i = 1; i < n; ++i)
		fl &= (a[i - 1].second <= a[i].second);

	if(fl)
	{
		for(int i = 0; i < n;)
		{
			int j = i;

			while(j + 1 < n && a[j + 1] == a[i])
				++j;

			subtract3 = mult(subtract3, fact[j - i + 1]);
			i = j + 1;
		}
	}
	else
	{
		subtract3 = 0;
	}

	sort(a, a + n, [&](auto lhs, auto rhs)
	{
		return tie(lhs.second, lhs.first) < tie(rhs.second, rhs.first);
	});

	for(int i = 0; i < n;)
	{
		int j = i;

		while(j + 1 < n && a[j + 1].second == a[i].second)
			++j;

		subtract2 = mult(subtract2, fact[j - i + 1]);
		i = j + 1;	
	}

	answ = sub(answ, subtract1);
	answ = sub(answ, subtract2);
	answ = add(answ, subtract3);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}