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

const int MAX_N = 100;
const int N_DIRS = 4;

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0,  0, -1, 1};

char table[MAX_N][MAX_N];
string cmd;

int n, m;

inline int check(const vector<int>& p)
{
	int curi = NIL, curj = NIL;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(table[i][j] == 'S')
			{
				curi = i;
				curj = j;
			}
		}
	}

	for(auto& ch: cmd)
	{
		int dir = p[ch - '0'];
		int newi = curi + di[dir];
		int newj = curj + dj[dir];

		if(newi < 0 || newj < 0)
			return 0;

		if(newi >= n || newj >= m)
			return 0;

		if(table[newi][newj] == '#')
			return 0;

		if(table[newi][newj] == 'E')
			return 1;

		curi = newi;
		curj = newj;
	}

	return 0;
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cin >> table[i][j];		
	}

	cin >> cmd;
	int answ = 0;

	vector<int> p(N_DIRS);
	iota(p.begin(), p.end(), 0);

	do
	{
		answ += check(p);
	}
	while(next_permutation(p.begin(), p.end()));

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}