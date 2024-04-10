#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

const ll P = 37 + randint(1, 10);

const int MAX_N = 5666;

string str;
int n, a, b;

ll prefhash[MAX_N], Ppow[MAX_N];
int func[MAX_N]; // func[i] in longest good string ending in i-th position
int dp[MAX_N];

inline ll getsubstrhash(int i, int len)
{
	return (i == 0 ? prefhash[len - 1] : (mod + prefhash[i + len - 1] - (Ppow[len] * prefhash[i - 1]) % mod) % mod);
}

#define USE_HASH

inline bool substrcmp(int i, int j, int len)
{
#ifdef USE_HASH
	return getsubstrhash(i, len) == getsubstrhash(j, len);
#else
	for(int k = 0; k < len; ++k)
		if(str[i + k] != str[j + k])
			return false;

	return true;
#endif
}

inline bool check(int i, int len)
{
	int lst = i - len + 1;

	for(int j = 0; j + len - 1 < lst; ++j)
		if(substrcmp(lst, j, len))
			return true;

	return false;
}

void solve()
{
	cin >> n >> a >> b >> str;

	prefhash[0] = str[0] - 'a';

	for(int i = 1; i < n; ++i)
		prefhash[i] = (P * prefhash[i - 1] + str[i] - 'a') % mod;

	Ppow[0] = 1;

	for(int i = 1; i <= n; ++i)
		Ppow[i] = (P * Ppow[i - 1]) % mod;

	for(int i = 0; i < n; ++i)
	{
		int L = 1, R = i + 2;

		if(check(i, L))
		{
			while(R - L > 1)
			{
				int M = (L + R) / 2;

				if(check(i, M))
					L = M;
				else
					R = M;
			}

			func[i] = L;
		}
	}

	for(int i = 0; i < n; ++i)
		dp[i] = (i + 1) * a;

	for(int i = 1; i < n; ++i)
	{
		dp[i] = min(dp[i], dp[i - 1] + a);

		for(int len = 1; len <= func[i] && i - len >= 0; ++len)
			dp[i] = min(dp[i], dp[i - len] + b);
	}

	cout << dp[n - 1] << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}