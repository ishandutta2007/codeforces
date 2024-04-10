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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

ll stupid(vector<int>& a)
{
	ll ret = 0;
	int n = a.size();

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			int x = a[i], y = a[j];

			bool ok = true;

			ok &= max(abs(a[i]), abs(a[j])) <= max(abs(a[i] + a[j]), abs(a[i] - a[j]));
			ok &= min(abs(a[i]), abs(a[j])) >= min(abs(a[i] + a[j]), abs(a[i] - a[j]));

			ret += ok;
		}
	}

	return ret;
}

ll smart(vector<int> a)
{
	int n = a.size();

	for(auto& el: a)
		el = abs(el);

	ll answ = 0;

	sort(a.begin(), a.end());

	int j = 0;
	int k = 0;

	for(int i = 0; i < n; ++i)
	{
		while(j + 1 < n && a[j + 1] <= 2 * a[i])
			++j;

		while(k < n && a[k] < a[i])
			++k;

		ll dlt = j - i + 1;
		answ += max(dlt, 0LL);
	}

	answ -= n;
	return answ;
}

void stress()
{
	for(int s = 0; s < 100000; ++s)
	{
		int len = randint(3, 10000);

		vector<int> a(len);

		for(auto& el: a)
			el = randint(-10000, 10000);

		ll smart_answ = smart(a);
		ll stupid_answ = stupid(a);

		if(smart_answ != stupid_answ)
		{
			cout << "WA!!" << endl;
			DBG(len); DBG(a);
			DBG(stupid_answ); DBG(smart_answ);
			exit(-1);
		}
	}
}

int main()
{
	fast_io();

#ifdef __LOCAL
	stress();
#endif

	int n;
	cin >> n;

	vector<int> a(n);

	for(auto& el: a)
		cin >> el;

	cout << smart(a) << endl;

	return 0;
}