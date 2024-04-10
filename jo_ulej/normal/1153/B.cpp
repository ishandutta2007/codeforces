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

const int MAX_N = 666;

int answ[MAX_N][MAX_N];
int maxinrow[MAX_N], maxincol[MAX_N];

void solve()
{
	int n, m, h;
	cin >> n >> m >> h;

	for(int j = 0; j < m; ++j)
		cin >> maxincol[j];

	for(int i = 0; i < n; ++i)
		cin >> maxinrow[i];

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> answ[i][j];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		if(maxinrow[i])
		{
			for(int j = 0; j < m; ++j)
			{
				if(answ[i][j] && maxincol[j] >= maxinrow[i])
				{
					answ[i][j] = maxinrow[i];
				}
			}
		}
	}

	for(int j = 0; j < m; ++j)
	{
		if(maxincol[j])
		{
			for(int i = 0; i < n; ++i)
			{
				if(answ[i][j] && maxinrow[i] >= maxincol[j])
				{
					answ[i][j] = maxincol[j];	
					break;
				}
			}
		}
	}

#define endl '\n'

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << answ[i][j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}