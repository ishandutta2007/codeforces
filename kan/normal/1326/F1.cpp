#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

#define popcount(x) __builtin_popcount(x)

const int maxn = 14;
const int maxmask = 1 << maxn;
const int maxhalfmask = 1 << 7;

int g[maxn][maxn];
char gs[maxn][20];
int n;
int dp[maxmask][maxhalfmask][maxn];
ll ans[maxmask];

inline void upd(int &a, int b)
{
	a += b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", gs[i]);
	for (int i =0 ; i < n; i++)
	{
		for (int j = 0; j < n; j++) g[i][j] = gs[i][j] - '0';
	}
	//n = 14;
	//for (int i = 0; i < n; i++)
	//{
		//for (int j = i + 1; j < n; j++) g[i][j] = g[j][i] = 1;
	//}
	//for (int mask = 0; mask < (1 << n); mask++) if (popcount(mask) == (n + 2) / 2 || popcount(mask) == (n + 1) / 2)
	//{
		//idtomask[nid] = mask;
		//masktoid[mask] = nid;
		//nid++;
	//}
	for (int i = 0; i < n; i++) dp[(1 << i)][0][i] = 1;
	for (int mask = 1; mask < (1 << n); mask++)
	{
		int k = popcount(mask);
		if (k >= (n + 2) / 2) continue;
		//cout << mask << ' ' << endl;
		for (int ms = 0; ms < (1 << (k - 1)); ms++)
		{
			for (int last = 0; last < n; last++) if (mask & (1 << last))
			{
				//cout << mask << ' ' << ms << ' ' << last << ' ' << dp[mask][ms][last] << endl;
				//cout << "! " << dp[3][1][1] << endl;
				for (int nxt = 0; nxt < n; nxt++) if (!(mask & (1 << nxt)))
				{
					//cout << " to " << (mask | (1 << nxt)) << ' ' << (ms | (g[last][nxt] << (k - 1))) << ' ' << nxt << endl;
					upd(dp[mask | (1 << nxt)][ms | (g[last][nxt] << (k - 1))][nxt], dp[mask][ms][last]);
					//cout << dp[mask | (1 << nxt)][ms | (g[last][nxt] << (k - 1))][nxt] << endl;
				}
			}
		}
	}
	int allmask = (1 << n) - 1;
	for (int mask = 0; mask < (1 << n); mask++) if (popcount(mask) == (n + 1) / 2)
	{
		int k = (n + 1) / 2 - 1;
		for (int last = 0; last < n; last++) if (mask & (1 << last))
		{
			int omask = allmask ^ mask ^ (1 << last);
			assert(omask != 0);
			int ok = popcount(omask) - 1;
			for (int ms1 = 0; ms1 < (1 << k); ms1++)
			{
				int rev = 0;
				int tms1 = ms1;
				for (int i = 0; i < k; i++)
				{
					rev = (rev << 1) | (tms1 & 1);
					tms1 >>= 1;
				}
				for (int ms2 = 0; ms2 < (1 << ok); ms2++) ans[ms2 | (rev << ok)] += (ll)dp[mask][ms1][last] * dp[omask][ms2][last];
			}
		}
	}
	for (int i = 0; i < (1 << (n - 1)); i++) printf("%lld ", ans[i]);
	printf("\n");
    return 0;
}