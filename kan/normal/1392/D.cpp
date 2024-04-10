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

const int maxn = 200'055;
const int inf = 1e9;

int c[maxn][2];
int ans[maxn][4];
int n;
char s[maxn];

inline void upd(int &a, int b)
{
	a = min(a, b);
}

void solve()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
	{
		int x = (s[i] == 'L' ? 0 : 1);
		c[i][x] =0 ;
		c[i][1 - x] = 1;
	}
	c[n][0] = c[n][1] = c[n + 1][0] = c[n + 1][1] = 0;
	int answer = inf;
	for (int st = 0; st < 4; st++)
	{
		for (int i = 2; i <= n + 3; i++)
		{
			for (int mask = 0; mask < 4; mask++) ans[i][mask] = inf;
		}
		ans[2][st] = c[0][(st & 1)] + c[1][st >> 1];
		for (int i = 2; i < n + 2; i++)
		{
			for (int mask = 0; mask < 4; mask++)
			{
				for (int t = 0; t < 2; t++)
				{
					int cmask = mask | (t << 2);
					if (cmask == 0 || cmask == 7) continue;
					cmask >>= 1;
					upd(ans[i + 1][cmask], ans[i][mask] + c[i][t]);
				}
			}
		}
		upd(answer, ans[n + 2][st]);
	}
	printf("%d\n", answer);
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