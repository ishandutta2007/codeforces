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

const int MAX_N = 2077;

int a[MAX_N], ord[MAX_N], n;

bitset<MAX_N> pref[MAX_N], suff[MAX_N];
int ok_pref[MAX_N], ok_suff[MAX_N];

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ord[i] = a[i];
	}

	sort(ord, ord + n);

	for(int i = 0; i < n; ++i)
		a[i] = lower_bound(ord, ord + n, a[i]) - ord;

	ok_pref[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i - 1];
		int val = a[i - 1];

		if(pref[i][val])
			break;

		pref[i][val] = 1;
		ok_pref[i] = 1;
	}

	ok_suff[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		suff[i] = suff[i - 1];
		int val = a[n - i];

		if(suff[i][val])
			break;

		suff[i][val] = 1;
		ok_suff[i] = 1;		
	}

	int answ = 0;
	int s = 0;

	while(s + 1 <= n && ok_suff[s + 1])
		++s;

	for(int p = 0; p <= n; ++p)
	{
		if(!ok_pref[p])
			break;

		while(p + s > n || !ok_suff[s] || (pref[p] & suff[s]).count())
			--s;

		DBG(p); DBG(s);

		answ = max(answ, p + s);
	}

	cout << n - answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}