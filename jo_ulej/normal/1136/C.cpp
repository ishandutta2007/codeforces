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

const int MAX_N = 506;

int matr1[MAX_N][MAX_N], matr2[MAX_N][MAX_N];
int n, m;

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> matr1[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> matr2[i][j];

	for(int t = 0; t <= n + m - 2; ++t)
	{
		vector<int> v1, v2;

		for(int i = 0; i < n; ++i)
		{
			int j = t - i;

			if(j >= 0 && j < m)
			{
				v1.push_back(matr1[i][j]);
				v2.push_back(matr2[i][j]);
			}
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		bool eq = true;

		for(int i = 0; i < v1.size(); ++i)
			eq &= (v1[i] == v2[i]);

		if(!eq)
		{
			DBG(t);
			DBG(v1); DBG(v2);
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}