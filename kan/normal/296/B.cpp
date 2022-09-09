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

const int MOD = 1000000007;

const int maxn = 100005;

char s[maxn], t[maxn];
int ans[maxn][5];

inline void upd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s%s", s, t);
	ans[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int tt = 0; tt <= 3; tt++)
		{
			for (int j = 0; j < 10; j++) if (s[i] == '?' || s[i] - '0' == j)
			{
				for (int k = 0; k < 10; k++) if (t[i] == '?' || t[i] - '0' == k)
				{
					int f = ((j > k ? 1 : 0) << 1) | (k > j ? 1 : 0);
					upd(ans[i + 1][tt | f], ans[i][tt]);
				}
			}
		}
	}
	printf("%d\n", ans[n][3]);
    return 0;
}