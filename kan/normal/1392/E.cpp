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

const int maxn = 30;

ll a[maxn][maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int pw = (i + j);
			if (i % 2 == 0) a[i][j] = 0;
			else a[i][j] = (1LL << pw);
			assert(a[i][j] < 5e15);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) printf("%lld ", a[i][j]);
		printf("\n");
	}
	fflush(stdout);
	int nq;
	scanf("%d", &nq);
	for (int q = 0; q < nq; q++)
	{
		ll k;
		scanf("%lld", &k);
		int cx = 0;
		int cy = 0;
		printf("1 1\n");
		while (cx < n - 1 || cy < n - 1)
		{
			int pw = (cx + cy + 1);
			if (cx % 2 == ((k >> pw) & 1)) cy++;
			else cx++;
			printf("%d %d\n", cx + 1, cy + 1);
		}
		fflush(stdout);
	}
    return 0;
}