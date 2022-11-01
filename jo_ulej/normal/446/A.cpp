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

	vector<int> jump(n, 1);

	for(int i = 0; i < n; ++i)
	{
		if(i > 0)
			jump[i] = max(jump[i - 1] - 1, 1);

		while(i + jump[i] < n && a[i + jump[i]] > a[i + jump[i] - 1])
			++jump[i];
	}

	int ans = -1;

	for(int l = 0; l < n; ++l)
	{
		ans = max(ans, jump[l]);

		if(l > 0)
			ans = max(ans, jump[l] + 1);

		int m = l + jump[l];

		if(m < n)
		{
			ans = max(ans, jump[l] + 1);

			if(m + 1 < n && m - 1 >= 0)
			{
				if(a[m - 1] + 1 < a[m + 1])
				{
					ans = max(ans, jump[l] + 1 + jump[m + 1]);
				}
			}
		}

		int m2 = l + jump[l] - 1;

		if(m2 + 1 < n && m2 - 1 >= 0)
		{
			if(a[m2 - 1] + 1 < a[m2 + 1])
				ans = max(ans, jump[l] + jump[m2 + 1]);
		}
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}