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

vector<ll> solve(vector<ll> a)
{
	ll g = 0;

	for(auto& x: a)
		g = GCD(g, x);

	for(auto& x: a)
		x /= g;

	vector<ll> even, odd;

	for(auto& x: a)
	{
		if(x % 2 != 0)
			odd.push_back(x);
		else
			even.push_back(x);
	}

	DBG(a); DBG(even); DBG(odd);

	if(even.empty())
	{
		for(auto& x: odd)
			x *= g;

		return odd;
	}
	else
	{
		auto answ = solve(even);

		if(len(answ) > len(odd))
		{
			for(auto& x: answ)
				x *= g;

			return answ;
		}
		else
		{
			for(auto& x: odd)
				x *= g;

			return odd;
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);

	for(auto& x: a)
		cin >> x;

	auto answ = solve(a);
	sort(answ.begin(), answ.end());

	vector<ll> ind;

	for(int i = 0; i < n; ++i)
	{
		auto iter = lower_bound(answ.begin(), answ.end(), a[i]);

		if(iter == answ.end() || *iter != a[i])
			ind.push_back(a[i]);
	}

	cout << len(ind) << endl;
	cout << ind << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}