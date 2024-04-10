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

const int N_BITS = 10;

vector<pair<char, int>> cmd[N_BITS];
int n;

inline int calc(int j, int input)
{
	int output = input;

	for(auto& c: cmd[j])
	{
		if(c.first == '^')
			output ^= c.second;
		else if(c.first == '|')
			output |= c.second;
		else
			output &= c.second;
	}

	return output;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		char op;
		int value;

		cin >> op >> value;

		for(int j = 0; j < N_BITS; ++j)
			cmd[j].emplace_back(op, (value >> j) & 1);
	}

	int zero = (1 << N_BITS) - 1, one = 0, inv = 0;

	for(int j = 0; j < N_BITS; ++j)
	{
		int f0 = calc(j, 0), f1 = calc(j, 1);

		if(f0 == 0 && f1 == 0)
			zero -= 1 << j;
		else if(f0 == 1 && f1 == 1)
			one += 1 << j;
		else if(f0 == 1 && f1 == 0)
			inv += 1 << j;
	}


	cout << 3 << endl;
	cout << "& " << zero << endl;
	cout << "| " << one << endl;
	cout << "^ " << inv << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}