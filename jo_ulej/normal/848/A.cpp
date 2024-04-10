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

const int MAX_N = (int)1e5 + 777;

int d[MAX_N], p[MAX_N], pch[MAX_N];

void solve()
{
	for(int i = 0; i < MAX_N; ++i)
		d[i] = INT_INF;

	d[0] = 0;

	for(int i = 1; i < MAX_N; ++i)
	{
		for(int j = 1;; ++j)
		{
			int dlt = (j * (j - 1)) / 2;

			if(dlt > i)
				break;

			if(d[i - dlt] + j < d[i])
				d[i] = d[i - dlt] + j, p[i] = i - dlt, pch[i] = j;	
		}	
	}

	int k;
	cin >> k;

	if(k == 0)
	{
		cout << "a" << endl;
		return;
	}

	string answ;
	char cur = 'a';

	while(k)
	{
		for(int i = 0; i < pch[k]; ++i)
			answ.push_back(cur);

		++cur;
		k = p[k];
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}