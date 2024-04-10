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

const int MAX_LEN = (int)1e6;

void solve()
{
	string str;
	cin >> str;
	ll answ = 0;
	int n = len(str);

	int last = NIL;

	for(int i = 0; i < n; ++i)
	{
		if(str[i] == '1')
		{
			int cnt0 = i - last - 1;
			int cur = 0;

			for(int j = i; j < n; ++j)
			{
				cur += cur;
				cur += str[j] - '0';

				if(cur > MAX_LEN)
					break;

				int diff = cur - (j - i + 1);

				if(diff >= 0 && diff <= cnt0)
					++answ;
			}

			last = i;
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}