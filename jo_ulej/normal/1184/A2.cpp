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

const int MAX_N = (int)2e5 + 77;

#ifdef __LOCAL
#define __gcd gcd
#endif

string str;
int n, met[MAX_N];

inline bool check(int k)
{
	vector<bool> used(n, false);

	for(int i = 0; i < n; ++i)
	{
		int cnt1 = 0;
		int j = i;

		while(!used[j])
		{
			used[j] = true;

			cnt1 += (str[j] == '1');
			j = (j + k) % n;
		}

		if(cnt1 & 1)
			return false;
	}

	return true;
}

void solve()
{
	cin >> n;
	cin >> str;

	vector<int> good;

	for(int d = 1; d * d <= n; ++d)
	{
		if(n % d == 0)
		{
			if(check(d))
				good.push_back(d);

			if(n / d != d && check(n / d))
				good.push_back(n / d);
		}
	}

	DBG(good);

	int answ = 0;

	for(int i = 0; i < n; ++i)
	{
		for(auto d: good)
		{
			if(__gcd(n, i) == d)
			{
				++answ;
				break;
			}
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}