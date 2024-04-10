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

const int MAX_N = 60;

ll a[MAX_N][MAX_N], b[MAX_N][MAX_N];
int n, m;

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> b[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(a[i][j] > b[i][j])
				swap(a[i][j], b[i][j]);

	bool ok = true;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(i != 0)
				ok &= (a[i - 1][j] < a[i][j]),
				ok &= (b[i - 1][j] < b[i][j]);

			if(j != 0)
				ok &= (a[i][j - 1] < a[i][j]),
				ok &= (b[i][j - 1] < b[i][j]);
		}
	}

	cout << (ok ? "Possible" : "Impossible") << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}