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

const int maxn = 2005;

int a[maxn];
int ans[2 * maxn][maxn];
int n;

inline void upd(int &a, int b)
{
	a = max(a, b);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) scanf("%d", &a[i]);
	for (int i =0; i <= 2 * n + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++) ans[i][j] = -1;
	}
	ans[2 * n][0] = 2 * n + 1;
	a[2 * n] = 2 * n + 1;
	for (int i = 2 * n; i > 0; i--)
	{
		for (int j = 0; j <= min(2 * n - i, n); j++) if (ans[i][j] >= 0)
		{
			//cout << i << ' ' << j << ' ' << ans[i][j] << endl;
			if (ans[i][j] > a[i - 1]) upd(ans[i - 1][j + 1], ans[i][j]);
			if (a[i] > a[i - 1]) upd(ans[i - 1][(2 * n - i) - j + 1], a[i]);
		}
	}
	if (ans[0][n] >= 0) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}