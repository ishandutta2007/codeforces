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

const int BIGGER = 1;
const int SMALLER = 2;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> info(n, NIL);
	vector<pii> temp;

	for(int qq = 0; qq < m; ++qq)
	{
		int t, l, r;
		cin >> t >> l >> r;
		--l, --r;

		if(t == 1)
		{
			for(int i = l; i < r; ++i)
				info[i] = SMALLER;
		}
		else
		{
			temp.emplace_back(l, r);
		}
	}

	for(auto seg: temp)
	{
		int l = seg.first, r = seg.second;
		bool ok = false;

		for(int i = l; i < r; ++i)
		{
			if(info[i] != SMALLER)
			{
				info[i] = BIGGER;
				ok = true;
			}
		}

		if(!ok)
		{
			cout << "NO\n";
			return;
		}
	}

	vector<int> answ(n, (int)1e8);

	for(int i = n - 2; i >= 0; --i)
	{
		if(info[i] == BIGGER)
			answ[i] = answ[i + 1] + 1;
		else
			answ[i] = answ[i + 1] - 1;
	}

	cout << "YES\n";
	cout << answ << "\n";
}

int main()
{
	fast_io();
	solve();

	return 0;
}