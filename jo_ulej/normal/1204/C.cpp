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

const int MAX_N = 107;
const int MAX_M = (int)1e6 + 77;

int edge[MAX_N][MAX_N];
int arr[MAX_M];
int n, m;

int dist[MAX_N][MAX_N];
int q[MAX_N], qsz;

int dp[MAX_M], prv[MAX_M], answ[MAX_M];

void solve()
{
	cin >> n;

	for(int v = 0; v < n; ++v)
	{
		string line;
		cin >> line;

		for(int u = 0; u < n; ++u)
			edge[v][u] = line[u] - '0';
	}

	for(int v = 0; v < n; ++v)
	{
		qsz = 0;
		q[qsz++] = v;

		for(int u = 0; u < n; ++u)
			dist[v][u] = INT_INF;

		dist[v][v] = 0;

		for(int j = 0; j < qsz; ++j)
		{
			int u = q[j];

			for(int w = 0; w < n; ++w)
			{
				if(edge[u][w] && dist[v][w] > dist[v][u] + 1)
				{
					dist[v][w] = dist[v][u] + 1;
					q[qsz++] = w;
				}
			}		
		}
	}

	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		cin >> arr[i];
		--arr[i];

		dp[i] = i + 1;
	}

	for(int i = 0; i < m; ++i)
	{
		prv[i] = i - 1;

		for(int j = i - 1; j >= 0 && j >= i - n; --j)
		{
			if(i - j != dist[arr[j]][arr[i]])
				continue;

			if(dp[j] + 1 < dp[i])
			{
				dp[i] = dp[j] + 1;
				prv[i] = j;		
			}
		}
	}

	int k = dp[m - 1];
	int cur = m - 1, ptr = k;
	cout << k << endl;

	while(cur != NIL)
	{
		answ[--ptr] = arr[cur] + 1;
		cur = prv[cur];
	}

	for(int i = 0; i < k; ++i)
		cout << answ[i] << " ";

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}