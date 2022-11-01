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

const ll mod = 998244353LL;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 77;
ll dp[MAX_N][2];

ll binpow(ll x, ll y)
{
	if(y == 0)
		return 1;
	if(y == 1)
		return x;
	if(y == 2)
		return (x * x) % mod;

	ll ret = binpow(x, y / 2);
	ret = (ret * ret) % mod;

	if(y & 1)
		ret = (ret * x) % mod;

	return ret;
}

ll calc(const vector<int>& a, ll k)
{
	ll ret = 1;
	int sz = a.size();

	for(int i = 0; i + 1 < sz; ++i)
		if(a[i] == a[i + 1] && a[i] != -1 && a[i + 1] != -1)
			return 0;

	vector<int> pos;

	for(int i = 0; i < sz; ++i)
		if(a[i] != -1)
			pos.push_back(i);

	if(pos.empty())
		return (k * binpow(k - 1, sz - 1)) % mod;

	if(pos.front() != 0)
	{
		ret = (ret * binpow(k - 1, pos.front())) % mod;
	}

	if(pos.back() != sz - 1)
	{
		ret = (ret * binpow(k - 1, sz - pos.back() - 1)) % mod;
	}

	for(int idx = 0; idx + 1 < pos.size(); ++idx)
	{
		int i = pos[idx], j = pos[idx + 1];

		ret = (ret * dp[j - i - 1][a[i] == a[j]]) % mod;
	}

	return ret;
}

void solve()
{
	int n;
   	ll k;

	cin >> n >> k;

	vector<int> a[2];

	for(int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;

		a[i % 2].push_back(val);
	}

	{
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[1][0] = max(k - 2, 0LL);
		dp[1][1] = k - 1;
		dp[2][0] = ((ll)(k - 1) * (ll)(k - 1) - (ll)(k - 2)) % mod;
		dp[2][1] = ((ll)(k - 1) * (ll)(k - 1) - (ll)(k - 1)) % mod;

		for(int len = 0; len <= n; ++len)
		{
			if(len > 2)
			{
				ll coeff = (k * (k - 1) - 2 * (k - 1) + 1) % mod;
				ll coeff2 = ((k - 1) * (k - 2)) % mod;
				dp[len][1] = ((k - 1) * dp[len - 2][1] + coeff2 * dp[len - 2][0]) % mod;
				dp[len][0] = ((k - 2) * dp[len - 2][1] + coeff * dp[len - 2][0]) % mod;
			}

			DBG(len);
			DBG(dp[len][1]);
			DBG(dp[len][0]);
		}
	}

	cout << (calc(a[0], k) * calc(a[1], k)) % mod << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}