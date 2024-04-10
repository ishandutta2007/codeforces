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

const int maxn = 305;

int ans[maxn][maxn];

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		for (int j =0 ; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			int need = 4;
			if (i == 0) need--;
			if (j == 0) need--;
			if (i == n - 1) need--;
			if (j == m - 1) need--;
			if (x > need) ok = false;
			ans[i][j] = need;
		}
	}
	if (!ok)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i =0; i < n; i++)
	{
		for (int j = 0; j < m; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		solve();
	}
    return 0;
}