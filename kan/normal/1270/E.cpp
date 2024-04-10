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

const int maxn = 1005;
const int inf = 1e6 + 6;

int x[maxn], y[maxn];
vector<int> ans;
bool was[2][2];
int n;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i] += inf;
		y[i] += inf;
	}
	while (true)
	{
		was[0][0] = was[1][0] = was[0][1] = was[1][1] = false;
		for (int i = 0; i < n; i++) was[x[i] % 2][y[i] % 2] = true;
		if (was[0][0] + was[0][1] + was[1][0] + was[1][1] >= 2)
		{
			bool ok = false;
			for (int i0 = 0; i0 < 2; i0++)
			{
				for (int i1 = 0; i1 < 2; i1++) if (was[i0][i1])
				{
					if (was[i0 ^ 1][i1] || was[i0][i1 ^ 1]) ok = true;
				}
			}
			if (ok)
			{
				for (int i = 0; i < n; i++) if ((x[i] + y[i]) % 2 == 0) ans.pb(i);
			} else
			{
				for (int i = 0; i < n; i++) if ((x[i]) % 2 == 0) ans.pb(i);
			}
			printf("%d\n", (int)ans.size());
			for (auto t : ans) printf("%d ", t + 1);
			printf("\n");
			break;
		}
		for (int i = 0; i < n; i++) x[i] /= 2, y[i] /= 2;
	}
    return 0;
}