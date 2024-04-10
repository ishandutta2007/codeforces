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

int MOD, BASE;

inline int conv(char ch)
{
	if(ch >= 'a' && ch <= 'z')
		return ch - 'a' + 1;

	if(ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 1 + 26;

	return ch - '0' + 1 + 26 + 26;
}

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

const int MAX_LEN = (int)1e6 + 777;

int prefhash[MAX_LEN], pw[MAX_LEN];
char answ[MAX_LEN];
int n, sz = 1;

inline void add(char ch)
{
	prefhash[sz] = add(mult(prefhash[sz - 1], BASE), conv(ch));
	answ[sz] = ch;

	++sz;
}

inline int get(int l, int r)
{
	--l;

	return sub(prefhash[r], mult(pw[r - l], prefhash[l]));
}

void solve()
{
	cin >> n;

	while(n--)
	{
		string word;
		cin >> word;

		int cur = 0, mx = 0, w = len(word);

		for(int i = 0; i < w; ++i)
		{
			cur = add(mult(cur, BASE), conv(word[i]));
			int pref = i + 1;

			if(pref < sz)
			{
				int h = get(sz - pref, sz - 1);

				if(cur == h)
					mx = pref;
			}
		}

		for(int i = mx; i < w; ++i)
			add(word[i]);
	}

	for(int i = 1; i < sz; ++i)
		cout << answ[i];

	cout << endl;
}

int main()
{
	vector<int> primes;

	for(int i = (int)1e9; i <= (int)1e9 + 500; ++i)
	{
		bool ok = true;

		for(int j = 2; j * j <= i; ++j)
		{
			if(i % j == 0)
			{
				ok = false;
				break;
			}		
		}

		if(ok)
			primes.push_back(i);
	}

	DBG(len(primes));
	MOD = primes[randint(0, len(primes) - 1)];
	BASE = randint(666, MOD - 1);

	pw[0] = 1;

	for(int i = 1; i < MAX_LEN; ++i)
		pw[i] = mult(pw[i - 1], BASE);

	fast_io();
	solve();

	return 0;
}