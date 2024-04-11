/* Im the best and i work like that */

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

#define F first
#define S second
#define all(x) x.begin(),x.end()
#define Mp make_pair
#define point complex
#define endl '\n'
#define SZ(x) (int)x.size()
#define fast_io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file_io freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define mashtali return cout << "Hello, World!", 0;

const int N = 1e6 + 10;
const int LOG = 20;
const ll mod = 1e9 + 7;
const ll inf = 8e18;
const double pi = acos(-1);
const ld eps = 1e-18;
const ld one = 1.;

ll pw(ll a, ll b, ll M, ll ret = 1) { if(a == 0) return 0; a %= M; while(b) { ret = (b & 1? ret * a % M : ret), a = a * a % M, b >>= 1; } return ret % M; }

mt19937 rng(time(nullptr));

int n, cen, cnt[N], H[N], sub[N];

vector < int > G[N];

void dfs(int v, int P = 0)
{
	H[v] = H[P] + 1;
	sub[v] = 1;
	for(auto u : G[v])
	{
		dfs(u, v);
		sub[v] += sub[u];
	}
}

ll tot, TOT, ans;

void solve(int v)
{
	int Mx = n - sub[v];
	for(auto u : G[v])
	{
		Mx = max(Mx, sub[u]);
	}
	ans = max(ans, tot + 1ll * Mx * (n - 1 - Mx));
	for(auto u : G[v])
	{
		tot += n - 2 * sub[u];
		solve(u);
		tot -= n - 2 * sub[u];
	}
	if(Mx <= (n / 2))
	{
		TOT = tot;
		cen = v;
	}
}

bitset < N > dp;

int main()
{
	fast_io;
	cin >> n;
	for(int i = 2; i <= n; i ++)
	{
		int x;
		cin >> x;
		G[x].push_back(i);
	}
	dfs(1);
	for(int i = 1; i <= n; i ++)
	{
		tot += H[i];
	}
	ans = max(ans, tot);
	solve(1);
	cnt[n - sub[cen]] ++;
	for(auto u : G[cen])
	{
		cnt[sub[u]] ++;
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
		///printf("i = %d cnt = %d\n", i, cnt[i]);
		if(cnt[i] == 0) continue;
		int rem = (cnt[i] - 1) >> 1;
		cnt[i] -= rem * 2;
		cnt[i * 2] += rem;
		for(int j = 0; j < cnt[i]; j ++)
		{
			dp = dp | (dp << i);
		}
	}
	///printf("cen = %d TOT = %lld\n", cen, TOT);
	for(int j = 0; j < N; j ++)
	{
		if(dp[j])
		{
			///printf("j = %d\n", j);
			ans = max(ans, TOT + 1ll * j * (n - 1 - j));
		}
	}
	cout << ans;
	return 0;
}

/* check corner case(n = 1?), watch for negetive index or overflow */