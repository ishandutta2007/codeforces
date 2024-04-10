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

const int maxn = 400005;

ll a[maxn], b[maxn];
ll ans[maxn];
ll opt[maxn];
int n, m, k;

inline void upd(ll &a, ll b)
{
	a = min(a, b);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a, a + n);
	for (int i =0; i < n; i++) b[i + 1] = a[i] + b[i];
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		opt[x] = max(opt[x], (ll)y);
	}
	for (int i = 1; i <= n; i++) ans[i] = b[n];
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= k; j++) upd(ans[i + j], ans[i] + b[i + j] - b[i + opt[j]]);
	}
	cout << ans[k] << endl;
    return 0;
}