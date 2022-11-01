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
	string s, t;
	cin >> s >> t;

	int n = s.size();
	vector<int> start(n, -1), end(n, -1);

	{
		string str = t + s;
		int n = str.size();

		vector<int> z(n, 0);

		int l = -1, r = -1;

		for(int i = 1; i < n; ++i)
		{
			if(i <= r)
				z[i] = min(z[i - l], r - i + 1);

			while(i + z[i] < n && str[z[i]] == str[i + z[i]])
				++z[i];

			if(i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}

		for(int i = 0; i < s.size(); ++i)
			if(z[t.size() + i] >= t.size())
				start[i + t.size() - 1] = i, end[i] = i + t.size() - 1;
	}

	vector<int> dp(n + 1, 0), suffsum(n + 1, 0);
	int lastbeg = -1;

	for(int i = n - 1; i >= 0; --i)
	{
		//bool fl = false;
		dp[i] = dp[i + 1];

		/*for(int j = i; j < n; ++j)
		{
			fl |= (start[j] >= i);

			if(fl)
				dp[i] = (dp[i] + 1 + dp[j + 1]) % mod;
		}*/

		if(end[i] != -1)
			lastbeg = i;

		if(lastbeg != -1)
		{
			int j = end[lastbeg];

			ll dlt = (n - j) + suffsum[j + 1];
			dp[i] = (dp[i] + dlt) % mod;
		}

		suffsum[i] = (suffsum[i + 1] + dp[i]) % mod;
	}

	DBG(start);
	DBG(end);

	for(int i = 0; i < n; ++i)
	{
		DBG(i);
		DBG(dp[i]);
	}

	cout << dp[0] << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}