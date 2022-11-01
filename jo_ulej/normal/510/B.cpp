#include <bits/stdc++.h>
 
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

const int MAX_N = 50;

char tbl[MAX_N][MAX_N];
bool met[MAX_N][MAX_N];
int n, m;
bool acyclic = true;

vector<pii> get_neighborhood(pii v)
{
	vector<pii> ret;

	if(v.first > 0)
		ret.emplace_back(v.first - 1, v.second);

	if(v.second > 0)
		ret.emplace_back(v.first, v.second - 1);

	if(v.first < n - 1)
		ret.emplace_back(v.first + 1, v.second);

	if(v.second < m + 1)
		ret.emplace_back(v.first, v.second + 1);

	return ret;
}

void dfs(pii v, pii parent)
{
	met[v.first][v.second] = true;

	for(auto u: get_neighborhood(v))
	{
		if(u == parent || tbl[u.first][u.second] != tbl[v.first][v.second])
			continue;

		if(!met[u.first][u.second])
		{
			dfs(u, v);
		}
		else
		{
			acyclic = false;
		}
	}
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> tbl[i][j];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			auto v = make_pair(i, j);

			if(!met[i][j])
				dfs(v, v);
		}
	}

	cout << (acyclic ? "No" : "Yes") << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}