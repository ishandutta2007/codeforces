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

#define popcount(x) __builtin_popcountll(x)

const int MOD = 998244353;

inline int mul(int a, int b)
{
	return ((ll)a * b) % MOD;
}

const int maxm = 60;
const int maxn = 200005;
const int maxnsmall = 40;
const int maxmask = 1 << 18;

int p2[maxn];
ll vforb[maxm];
int n, m;
int nfree;
ll row[maxm];
int answer[maxm];
int ans[maxnsmall][maxmask];

void add(ll x)
{
	for (int i = 0; i < m; i++) if ((x >> i) & 1)
	{
		if (vforb[i] == -1)
		{
			vforb[i] = x;
			return;
		}
		x ^= vforb[i];
	}
	assert(x == 0);
	nfree++;
}

inline void swapb(ll &x, int a, int b)
{
	int va = (x >> a) & 1;
	int vb = (x >> b) & 1;
	if (va ^ vb)
	{
		x ^= (1LL << a);
		x ^= (1LL << b);
	}
}

inline void upd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
	p2[0] = 1;
	for (int i = 1; i < maxn; i++) p2[i] = mul(p2[i - 1], 2);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) vforb[i] = -1;
	nfree = 0;
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%lld", &x);
		add(x);
	}
	//cout << nfree << endl;
	n = 0;
	for (int i = 0; i < m; i++) if (vforb[i] != -1)
	{
		row[n] = vforb[i];
		if (i != n)
		{
			for (int j = 0; j <= n; j++) swapb(row[j], n, i);
		}
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++) if ((row[j] >> i) & 1) row[j] ^= row[i];
	}
	for (int i = 0; i < n; i++)
	{
		assert((row[i] >> i) & 1);
		assert((row[i] & ((1LL << i) - 1)) == 0);
		//cout << row[i] << ' ';
		//cout << endl;
	}
	if (n < m - n)
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			ll v = 0;
			for (int i =0; i < n; i++) if ((mask >> i) & 1) v ^= row[i];
			answer[popcount(v)]++;
		}
	} else
	{
		for (int i = 0; i < n; i++) row[i] >>= n;
		ans[0][0] = 1;
		int km = (1 << (m - n));
		for (int i = 0; i < n; i++)
		{
			for (int taken = i; taken >= 0; taken--)
			{
				for (int mask = 0; mask < km; mask++)
				{
					upd(ans[taken + 1][mask ^ row[i]], ans[taken][mask]);
				}
			}
		}
		for (int i = 0; i <= n; i++)
		{
			for (int mask = 0; mask < km; mask++)
			{
				upd(answer[popcount(mask) + i], ans[i][mask]);
			}
		}
	}
	for (int i = 0; i <= m; i++) answer[i] = mul(answer[i], p2[nfree]);
	for (int i = 0; i <= m; i++) printf("%d ", answer[i]);
	printf("\n");
    return 0;
}