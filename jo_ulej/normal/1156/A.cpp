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

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for(auto& el: a)
		cin >> el;

	int answ = 0;

	for(int i = 1; i < n; ++i)
	{
		int x = a[i];
		int y = a[i - 1];

		if(x == y)
		{
			cout << "Infinite" << endl;
			return;
		}

		if(y == 1)
		{
			if(x == 2)
				answ += 3;
			else
				answ += 4;
		}
		else if(y == 2)
		{
			if(x == 1)
			{
				answ += 3;
			}
			else
			{
				cout << "Infinite" << endl;
				return;
			}
		}
		else
		{
			if(x == 1)
			{
				answ += 4;
			}
			else
			{
				cout << "Infinite" << endl;
				return;
			}
		}
	}

	for(int i = 1; i + 1 < n; ++i)
	{
		if(a[i] == 1 && a[i - 1] == 3 && a[i + 1] == 2)
			--answ;
	}

	cout << "Finite" << endl;
	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}