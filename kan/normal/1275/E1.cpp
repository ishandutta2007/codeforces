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

const int maxn = 505;

int a[maxn][maxn];

int main()
{
	int r, c;
	scanf("%d%d", &r, &c);
	if (r == 1 && c == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if (r == 1)
	{
		for (int j = 0; j < c; j++) printf("%d ", j + 2);
		printf("\n");
		return 0;
	}
	if (c == 1)
	{
		for (int j = 0; j < r; j++) printf("%d\n", j + 2);
		return 0;
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) a[i - 1][j - 1] = i * (j + r);
	}
	set<int> was;
	int mx = 0;
	for (int i = 0; i < r; i++)
	{
		int g = 0;
		for (int j = 0; j < c; j++) g = __gcd(g, a[i][j]);
		assert(!was.count(g));
		was.insert(g);
		mx = max(mx, g);
	}
	for (int j = 0; j < c; j++)
	{
		int g = 0;
		for (int i = 0; i < r; i++) g = __gcd(g, a[i][j]);
		assert(!was.count(g));
		was.insert(g);
		mx = max(mx, g);
	}
	//cout << mx << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
    return 0;
}