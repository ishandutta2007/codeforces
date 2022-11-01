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

#define int long long 

const int MAX_N = (int)2e5 + 777;

int n, m, k, q;

pii pts[MAX_N];
int good_cols[MAX_N];

inline int dist(int x1, int y1, int x2, int y2)
{
	if(x1 == x2)
		return abs(y1 - y2);

	int answ = INT_INF;
	
	int j = lower_bound(good_cols, good_cols + q, y1) - good_cols;

	if(j < q)
	{
		answ = min(answ, abs(y1 - good_cols[j]) + abs(y2 - good_cols[j]));
	}

	if(j > 0)
	{
		--j;
		answ = min(answ, abs(y1 - good_cols[j]) + abs(y2 - good_cols[j]));
	}
	
	return answ + abs(x1 - x2);
}

void solve()
{
	cin >> n >> m >> k >> q;

	for(int i = 0; i < k; ++i)
		cin >> pts[i].first >> pts[i].second;

	for(int i = 0; i < q; ++i)
		cin >> good_cols[i];

	sort(good_cols, good_cols + q);
	sort(pts, pts + k);

	int dist1 = 0, dist2 = 0;
	int x1 = 1, y1 = 1, x2 = 1, y2 = 1;

	for(int i = 0; i < k;)
	{
		int j = i;

		while(j + 1 && pts[j + 1].first == pts[i].first)
			++j;

		int new_x2 = pts[j].first, new_y2 = pts[j].second;
		int new_dist2 = INT_INF;

		{
			int sum1 = dist1 + dist(x1, y1, pts[i].first, pts[i].second);
			int sum2 = dist2 + dist(x2, y2, pts[i].first, pts[i].second);

			for(int ind = i; ind + 1 <= j; ++ind)
			{
				int dlt = dist(pts[ind].first, pts[ind].second, pts[ind + 1].first, pts[ind + 1].second);

				sum1 += dlt;
				sum2 += dlt;
			}

			new_dist2 = min(sum1, sum2);
		}

		int new_x1 = pts[i].first, new_y1 = pts[i].second;
		int new_dist1 = INT_INF;

		{
			int sum1 = dist1 + dist(x1, y1, pts[j].first, pts[j].second);
			int sum2 = dist2 + dist(x2, y2, pts[j].first, pts[j].second);

			for(int ind = j; ind - 1 >= i; --ind)
			{
				int dlt = dist(pts[ind].first, pts[ind].second, pts[ind - 1].first, pts[ind - 1].second);

				sum1 += dlt;
				sum2 += dlt;
			}

			new_dist1 = min(sum1, sum2);
		}

		x1 = new_x1;
		y1 = new_y1;

		x2 = new_x2;
		y2 = new_y2;

		dist1 = new_dist1;
		dist2 = new_dist2;

		i = j + 1;
	}

	cout << min(dist1, dist2) << endl;
}

signed main()
{
	fast_io();
	solve();

	return 0;
}