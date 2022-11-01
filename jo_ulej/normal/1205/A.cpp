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

void solve()
{
	int n;
	cin >> n;

	vector<ll> answ(2 * n, NIL);

	for(int i = 0; i < n; ++i)
	{
		if(i & 1)
		{
			answ[i] = 2 * i + 2;
			answ[i + n] = 2 * i + 1;
		}
		else
		{
			answ[i] = 2 * i + 1;
			answ[i + n] = 2 * i + 2;
		}
	}

	DBG(answ);

	vector<ll> b;

	ll sum = 0;

	for(int i = 0; i < n; ++i)
		i += answ[i];

	for(int i = 0; i < 2 * n; ++i)
	{
		b.push_back(sum);

		int j = i + n;

		if(j >= 2 * n)
			j -= 2 * n;

		sum -= answ[i];
		sum += answ[j];
	}

	int mn = *min_element(b.begin(), b.end());
	int mx = *max_element(b.begin(), b.end());

	if(mx > mn + 1)
	{
		cout << "NO" << endl;
	}
	else
	{
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